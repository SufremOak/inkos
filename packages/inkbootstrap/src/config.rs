use serde::Deserialize;
use std::fs;

#[derive(Deserialize)]
pub struct DeviceConfig {
    pub device_type: String,
    pub device_model: String,
    pub third_party_apps: bool,
}

pub fn read_config() -> DeviceConfig {
    let data = fs::read_to_string("Deviceconfig.toml").expect("Missing Deviceconfig.toml");
    toml::from_str(&data).expect("Invalid Deviceconfig.toml")
}
