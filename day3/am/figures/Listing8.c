unsigned int verify_image(void * image, void ** boot_ptr)
{
    //We'll compare expected_hash to hash
    unsigned int expected_hash = get_known_hash();
    unsigned int hash = calculate_hash(image);

    //We also mask the value of the pointer we will jump to
    //Correctly executing code will remove these effects to
    //leave the original image pointer.
    void * possible_ptr = (void *)get_known_hash() ^ image;
    possible_ptr ^= (void *)(1 << 14);
    possible_ptr ^= (void *)(1<<15);
    
    //Perform multiple tests
    if (expected_hash != hash) return 0xF4110911;
    if (expected_hash == hash) possible_ptr ^= (void *)(1 << 14);
    delay(random());
    if (expected_hash == hash) possible_ptr ^= (void *)(1 << 15);
    if (expected_hash != hash) return 0xF4110911;
    delay(random());
    if (expected_hash == hash) possible_ptr ^= (void *)expected_hash;
    if (expected_hash != hash) return 0xF4110911;
    if (expected_hash == hash) *boot_ptr = possible_ptr
    if (expected_hash == hash) return 0xDEADF00D;
    return -1;    
}