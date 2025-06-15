import sys
import tarfile
import shutil
import os

from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QVBoxLayout, QLabel, QPushButton, QTabWidget, QFileDialog, QMessageBox, QAction, QInputDialog
)

class PenUtility(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Pen Utility")
        self.setGeometry(100, 100, 400, 250)
        self.init_ui()
        self.init_menubar()

    def init_ui(self):
        self.tabs = QTabWidget()
        self.setCentralWidget(self.tabs)

        # Info Tab
        info_tab = QWidget()
        info_layout = QVBoxLayout()
        info_label = QLabel("Welcome to Pen Utility!\n\nA simple utility inspired by RockBox Utility.")
        info_layout.addWidget(info_label)
        info_tab.setLayout(info_layout)
        self.tabs.addTab(info_tab, "Info")

        # Install Tab
        install_tab = QWidget()
        install_layout = QVBoxLayout()
        install_label = QLabel("Install firmware or tools to your device.")
        install_btn = QPushButton("Install...")
        install_btn.clicked.connect(self.install_action)
        install_layout.addWidget(install_label)
        install_layout.addWidget(install_btn)
        install_tab.setLayout(install_layout)
        self.tabs.addTab(install_tab, "Install")

        # Backup Tab
        backup_tab = QWidget()
        backup_layout = QVBoxLayout()
        backup_label = QLabel("Backup your device data.")
        backup_btn = QPushButton("Backup...")
        backup_btn.clicked.connect(self.backup_action)
        backup_layout.addWidget(backup_label)
        backup_layout.addWidget(backup_btn)
        backup_tab.setLayout(backup_layout)
        self.tabs.addTab(backup_tab, "Backup")

        # About Tab
        about_tab = QWidget()
        about_layout = QVBoxLayout()
        about_label = QLabel("Pen Utility v1.0\n\nCreated with PyQt5.\nInspired by RockBox Utility.")
        about_layout.addWidget(about_label)
        about_tab.setLayout(about_layout)
        self.tabs.addTab(about_tab, "About")

    def init_menubar(self):
        menubar = self.menuBar()

        # File menu
        file_menu = menubar.addMenu("File")
        exit_action = QAction("Exit", self)
        exit_action.triggered.connect(self.close)
        file_menu.addAction(exit_action)

        # Help menu
        help_menu = menubar.addMenu("Help")
        about_action = QAction("About", self)
        about_action.triggered.connect(self.show_about_dialog)
        help_menu.addAction(about_action)

    def show_about_dialog(self):
        QMessageBox.information(self, "About Pen Utility", "Pen Utility v1.0\n\nCreated with PyQt5.\nInspired by RockBox Utility.")

    def install_action(self):
        file_name, _ = QFileDialog.getOpenFileName(self, "Select Firmware/Tool Tarball", "", "Tarball Files (*.tar)")
        if not file_name:
            return

        # Ask for mount point or device letter
        target_dir = QFileDialog.getExistingDirectory(self, "Select Mount Point or Device Letter")
        if not target_dir:
            return

        # Confirm extraction
        reply = QMessageBox.question(
            self, "Confirm Install",
            f"Extract contents of:\n{file_name}\n\nto:\n{target_dir}\n\nProceed?",
            QMessageBox.Yes | QMessageBox.No
        )
        if reply != QMessageBox.Yes:
            return

        try:
            with tarfile.open(file_name, "r") as tar:
                tar.extractall(path=target_dir)
            QMessageBox.information(self, "Install", f"Successfully extracted tarball to:\n{target_dir}")
        except Exception as e:
            QMessageBox.critical(self, "Install Error", f"Failed to extract tarball:\n{str(e)}")

    def backup_action(self):
        dir_name = QFileDialog.getExistingDirectory(self, "Select Backup Directory")
        if dir_name:
            QMessageBox.information(self, "Backup", f"Selected directory: {dir_name}\n(Backup not implemented)")

# Entry point
def main():
    app = QApplication(sys.argv)
    window = PenUtility()
    window.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
