extern crate uuid;

use uuid::Uuid;

fn main() {
    println!("{}", Uuid::new_v4());
}