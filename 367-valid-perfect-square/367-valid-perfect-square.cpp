class Solution {
public:
bool isPerfectSquare(int num) {
float x;
x = sqrt(num);
if(x == (int) x){
return true;
}
else{
return false;
}
}
};