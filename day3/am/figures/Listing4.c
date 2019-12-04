void * boot_image;

load_image(boot_image);

// veri-fy_image() Returns -1 if
// verification fails
if (verify_image(boot_image) < 0) {
    //User must reset device to retry
    while(1);
}

jump_to_image(boot_image);