void * boot_image;

load_image(boot_image);

delay(random());

if (verify_image(boot_image)) {
    jump_to_image(boot_image);
}

while(1);