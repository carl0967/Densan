while(<>){
  [s/\r\n/\r/]
}continue{
  print $_;
}
