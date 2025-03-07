#include "ivs_example.h"

int main(){

  BankovniUcet ucet = BankovniUcet();

  try{
    ucet.vyber(-100);
  }
  catch (MyException1& e){
    std::cout<<__LINE__<<": vyjimka1 zachycena: "<<e.what() <<std::endl;
  }
  catch (MyException2& e){
    std::cout<<__LINE__<<": vyjimka2 zachycena: "<<e.what() <<std::endl;
  }
  catch (std::exception& e){
    std::cout<<__LINE__<<": vyjimka zachycena: "<<e.what() <<std::endl;
  }

  try{
    ucet.vyber(100);
  }
  catch (MyException1& e){
    std::cout<<__LINE__<<": vyjimka1 zachycena: "<<e.what() <<std::endl;
  }
  catch (MyException2& e){
    std::cout<<__LINE__<<": vyjimka2 zachycena: "<<e.what() <<std::endl;
  }
  catch (std::exception& e){
    std::cout<<__LINE__<<": vyjimka zachycena: "<<e.what() <<std::endl;
  }


  try{
    ucet.vyber(-100);
  }
  catch (MyException1& e){
    std::cout<<__LINE__<<": vyjimka1 zachycena: "<<e.what() <<std::endl;
  }
  catch (MyException2& e){
    std::cout<<__LINE__<<": vyjimka2 zachycena: "<<e.what() <<std::endl;
  }
  catch (std::exception& e){
    std::cout<<__LINE__<<": vyjimka zachycena: "<<e.what() <<std::endl;
  }
  
  try{
    ucet.vloz(-100);
  }
  catch (MyException1& e){
    std::cout<<__LINE__<<": vyjimka1 zachycena: "<<e.what() <<std::endl;
  }
  catch (MyException2& e){
    std::cout<<__LINE__<<": vyjimka2 zachycena: "<<e.what() <<std::endl;
  }
  catch (std::exception& e){
    std::cout<<__LINE__<<": vyjimka zachycena: "<<e.what() <<std::endl;
  }
  
  try{
    ucet.vloz(100);
  }
  catch (MyException1& e){
    std::cout<<__LINE__<<": vyjimka1 zachycena: "<<e.what() <<std::endl;
  }
  catch (MyException2& e){
    std::cout<<__LINE__<<": vyjimka2 zachycena: "<<e.what() <<std::endl;
  }
  catch (std::exception& e){
    std::cout<<__LINE__<<": vyjimka zachycena: "<<e.what() <<std::endl;
  }

  return 0;
}