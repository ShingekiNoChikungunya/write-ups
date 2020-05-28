  char my_name [16];
  char my_username [16];
  char my_password [16];
  char my_incredible_biography [64];

  int my_checked_number = 0;


  input(my_name,16);
  input(my_username,16);
  input(my_password,16);
  input(my_incredible_biography,128);

  if (my_checked_number == -0x3f2c2ff3) {
    //ITS A MATCH
    //read flag logic
    read_flag();
  }else{
    //you failed
    //you're not cool enough
    failed();
  }
