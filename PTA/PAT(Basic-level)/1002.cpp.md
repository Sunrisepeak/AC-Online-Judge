/* 
```cpp
    ==code-begin==*/
#include<iostream>
#include<string>
#include<map>
int sum_bit(std::string str)
{
    int sum{0};
    for(auto c : str)
    {
        sum += c - '0';     //calulater sum to bit of str
    }
    return sum;

}

int main()
{
	std::map<int, std::string> num_pingyin{
		{0, "ling"},
		{1, "yi"},
		{2, "er"},
		{3, "san"},
		{4, "si"},
		{5, "wu"},
		{6, "liu"},
		{7, "qi"},
		{8, "ba"},
		{9, "jiu"}
	
	};	//0-9 and its spell
	std::string num_str{""};//save input(c++11 init list)
	std::cin >> num_str;    //read
    std::string sum_str = std::to_string(sum_bit(num_str));  //sum tostring
    for(decltype(sum_str.size()) i = 0; i < sum_str.size(); i++)
    {
        int num = sum_str[i] - '0';   //get num(0~9) every unit
        std::cout << num_pingyin[num] <<
                     (i + 1u != sum_str.size() ? " " : "\n");    //deal space_key in the end
    }
	return 0;
}
/*
```
   ==code-end==*/

/*
# ANALYZE

## Involved with knowledge and skill

## Problem-solving ideal

## Time complexity

## Space complexity
 
 */
