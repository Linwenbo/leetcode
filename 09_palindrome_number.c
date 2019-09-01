bool isPalindrome(int x){
  if ( x < 0 || (x % 10 == 0) && (x != 0)) return false;
    
  int revert_num=0;
  while (x > revert_num){
    revert_num=revert_num*10+x%10;
    x/=10;
  }
  return x == revert_num || x == revert_num / 10;
}
