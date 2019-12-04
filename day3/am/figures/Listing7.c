void * test_image;
void * boot_image = ERROR_HANDLER_ADDRESS;
unsigned int status = 0;

load_image(test_image);

delay(random());

status = verify_image(test_image, &boot_image)

//verify_image copies test_image to boot_image
if (status == 0xDEADF00D) {
    //Looks OK...
    delay(random());
    jump_to_image(boot_image);
} else if (status == 0xF4110911) {
    //Signature failed
    test_image = NULL;
    boot_image = NULL;
    while(1);
} else {
    //Unexpected result - fault attack??
    erase_sensitive_data();
    while(1);
}

boot_backup_image();