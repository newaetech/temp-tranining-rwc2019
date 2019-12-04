void write_bytes(char * data[], unsigned int datalen) {
    for(int i = 0; i < datalen; i++){
        uart_write(data[i]);
    }
}


