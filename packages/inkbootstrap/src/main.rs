mod config;
mod build;
mod install;

use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(name = "inkbootstrap")]
#[command(author, version, about)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
enum Commands {
    Build,
    Install {
        #[arg(short = 'D', long)]
        create_system_folder: bool,

        #[arg(short = 'm', long)]
        no_format: bool,

        #[arg(short = 'I', long)]
        input: String,

        #[arg(short = 'T', long)]
        target: String,
    },
}

fn main() {
    let cli = Cli::parse();

    match cli.command {
        Commands::Build => build::run(),
        Commands::Install {
            create_system_folder,
            no_format,
            input,
            target,
        } => install::run(&input, &target, create_system_folder, no_format),
    }
}
