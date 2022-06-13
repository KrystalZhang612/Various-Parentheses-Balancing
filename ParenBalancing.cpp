#include<stack>

#include<iostream>

using namespace std;


//here, we are using stack to check if the parentheses are balanced. 

//Algorithm details: 

//create an empty stack to allocate 
//Traverse the entire input string
//If the current character is a opening bracket: ‘(‘ or ‘{‘ or ‘[‘, push it to the top of the stack. 
//If the current character is a closing bracket: ‘)’ or ‘}’ or ‘]’, pop a character from the stack 
//check if the current character is a corresponding parenthesis/bracket, if matches then pop it from stack.
//return true or false as matched or unmatched, the string traversal is done, return the empty stack.


class matching_parentheses_class{
      
private:
      
      bool comparison(char top_of_myStack, char myChar){
            
            //if top of myStack is an opening bracket
            //and myChar as the InputString[i] is its corresponding closing bracket 
            //then matches, return true. 
            
            if( top_of_myStack =='(' && myChar ==')' )
                  
                  return true;
            
            else if(top_of_myStack =='{' && myChar =='}')
                  
                  return true;
            
            else if(top_of_myStack =='[' && myChar ==']')
                  
                  return true;
            else
                  //if not finding any matches, return false. 
            
                  return false;
      }
      
      
public:
      
      //matching_parentheses boolean function
      
      //declare the input string here
      
      bool matching_parentheses(char InputString[]){

            //create a stack to allocate 
            
            stack<char> myStack;
            
            int i=0;

            //traverse the entire input string to check matching parentheses
            

            while(InputString[i]) {
                  
                  //if InputString[i] character is an opening bracket
                  //push it to myStack at top.
                  
                  if( InputString[i]=='(' || InputString[i]=='{' || InputString[i]=='[' ) {
                        
                        myStack.push(InputString[i]);
                  }
                  
                  //if InputString[i] character is a closing bracket
                  //get the top character from myStack and match it to the current character. 
                  //if successfully match, pop it out from myStack and return true. 
                  //otherwise, not matching, return false, continue traversing. 
                  

                  if( InputString[i]==')' || InputString[i]=='}' || InputString[i]==']' ) {
                  
                        if( myStack.empty() || !comparison(myStack.top(), InputString[i]) ) {
                              return false;
                        }
                        else {
                              //the brackets matched
                              //return true and pop it from stack
                              myStack.pop();
                        }
                   }
                  i++;  //keep traversing. 
            }
            
            return myStack.empty();
            

            //if myStack is empty then the corresponding parentheses are either matching or not matching. 
            //but since we have already gotten the result of either true or false.
            //we just need to return the empty stack here
            
      
      }


};

//end of the class 

//driver 


int main(int argc, char *argv[]) {
      
      //assume the strings are not too long
      
      char myString[45];
      
      matching_parentheses_class temp;


      cout<<"Input: "; 
      
      //prompt user to input a string 
      
      cin.getline(myString,45);
      
      //Return true if the input string is empty
      
      //Return true if there is only letters in the string
      

      if (temp.matching_parentheses(myString))  {

            cout<<"Output: true"<<endl;
            
      }
            else{
                  
            cout<<"Output: false"<<endl;
      }

      return 0;

}
