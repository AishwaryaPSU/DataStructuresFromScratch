#include<iostream>
using namespace std;
int main(){
var chars = "0123456789";
var random = new Random();
var result = new string(Enumerable.Repeat(chars, 6).Select(s => s[random.Next(s.Length)]).ToArray());
string random_num;
password = result.ToString();
}