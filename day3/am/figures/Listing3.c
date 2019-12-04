void * boot_image;

load_image(boot_image);

if (verify_image(boot_image)) {
    jump_to_image(boot_image);
}

boot_backup_image();