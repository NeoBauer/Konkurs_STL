#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>

int main() {

  std::string sen("Ala ma kota a kot ma Ale, jednak to bylo dawno temu.");

  std::vector<int> where_is_space{};
  std::vector<std::pair<int, int>> words_to_remove{};
  int fake_iterator = 0;

  std::count_if(sen.begin(), sen.end(), [&where_is_space, fake_iterator](char& el)
    mutable{
    if(el == ' ' || el == ',' || el =='.') {
      where_is_space.push_back(fake_iterator);
      }
      fake_iterator++;
    return false;
    });

    for (auto el : where_is_space) std::cout << el << '\n';


std::adjacent_find(where_is_space.begin(), where_is_space.end(), [&words_to_remove, sen, where_is_space](int el1, int el2)
mutable{ 
  std::cout << el1 << " i " <<el2<<'\n';

  if (*where_is_space.begin() == 4)         words_to_remove.push_back(std::make_pair(0, 4));
  if ((el2-el1) == 5)   words_to_remove.push_back(std::make_pair(el1+1, 4));

  if (*where_is_space.begin() == 6)         words_to_remove.push_back(std::make_pair(0, 6));
  if ((el2-el1) == 7)   words_to_remove.push_back(std::make_pair(el1+1, 6));

 return false;

  });

for (auto el : words_to_remove) std::cout <<"First letter to remove: "<<el.first << " and how many letter to remove: " << el.second << '\n';
int iterator2 = 0;

std::count_if(words_to_remove.begin(), words_to_remove.end(), [&sen, words_to_remove, &iterator2](auto pair)
mutable{  
     //std::string::iterator it=sen.begin();
     

     std::remove_if(sen.begin(), sen.end(),[words_to_remove, pair, &iterator2 ](auto letter){
     if(iterator2>=pair.first && iterator2<=(pair.first+pair.second-1))
     {  std::cout<<"jestem w warunku"<<'\n';
        return true;
        
     }
     iterator2++;
     std:: cout<< iterator2 << '\n'; 
     //it++; 
       
     return false; });

 return 0; 
 });
 std::cout << sen;
}
