while(<>){
  [s/\n/\r\n/]
}continue{
  print $_;
}
