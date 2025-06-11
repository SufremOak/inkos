use colored::*;
use indicatif::{ProgressBar, ProgressStyle};
use std::{fs, process::Command, thread, time::Duration};

pub fn run(input: &str, target: &str, create_folder: bool, no_format: bool) {
    println!("{}", "💿 Installing bundle...".cyan());

    if create_folder {
        println!("{} {}", "📁 Creating target folder:".bold(), target);
        fs::create_dir_all(target).unwrap();
    }

    if no_format {
        println!("{}", "⚠️ Skipping device formatting.".yellow());
    }

    let pb = ProgressBar::new_spinner();
    pb.set_style(
        ProgressStyle::with_template("{spinner} {msg}")
            .unwrap()
            .tick_chars("⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏"),
    );
    pb.enable_steady_tick(Duration::from_millis(80));
    pb.set_message("Extracting .tar bundle to target...");

    thread::sleep(Duration::from_secs(1)); // Simulate time for realism

    let status = Command::new("tar")
        .args(["-xf", input, "-C", target])
        .status()
        .expect("❌ Failed to extract tar file");

    pb.finish_and_clear();

    if status.success() {
        println!(
            "{} {}",
            "✅ Installed to:".bold(),
            target.bright_green()
        );
    } else {
        println!("{}", "❌ Install failed.".red());
    }
}
