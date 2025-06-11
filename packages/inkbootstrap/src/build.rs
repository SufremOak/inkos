use crate::config::read_config;
use colored::*;
use indicatif::{ProgressBar, ProgressStyle};
use std::{fs, process::Command, thread, time::Duration};

pub fn run() {
    let config = read_config();
    let out_dir = format!("out/inkos-1.0.0-{}", config.device_model);
    let tar_file = format!("{}.tar", out_dir);

    println!("{}", "🔧 Starting build...".bright_blue());

    if !config.third_party_apps {
        println!(
            "{} {}",
            "📦 Mode:".bold(),
            "Web UI Only (no 3rd-party apps)".yellow()
        );
    } else {
        println!(
            "{} {}",
            "📦 Mode:".bold(),
            "Full OS with 3rd-party app support".green()
        );
    }

    fs::create_dir_all(&out_dir).unwrap();

    let pb = ProgressBar::new_spinner();
    pb.set_style(
        ProgressStyle::with_template("{spinner} {msg}")
            .unwrap()
            .tick_chars("⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏"),
    );
    pb.enable_steady_tick(Duration::from_millis(80));
    pb.set_message("Creating .tar archive...");

    thread::sleep(Duration::from_secs(1)); // Simulate some delay

    let tar_status = Command::new("tar")
        .args(["-cf", &tar_file, "-C", "out", &format!("inkos-1.0.0-{}", config.device_model)])
        .status()
        .expect("❌ Failed to create .tar archive");

    pb.finish_and_clear();

    if tar_status.success() {
        println!(
            "{} {}",
            "✅ Build complete:".bold(),
            tar_file.bright_green()
        );
    } else {
        println!("{}", "❌ Tarball creation failed.".red());
    }
}
