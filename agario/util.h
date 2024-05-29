//#@title \#TODO\# The Code You Will Need To Edit
//%%cpp -n util.h -s xcode

// #TODO# The Code You Will Need To Edit

// #TODO# The Code You Will Need To Edit
#include "moves.h"
#include "helpers.h"

// Allocates memory using malloc for an array of characters
void allocate_memory(Character** characters, int N_CHARACTERS){
  //
  *characters = (Character*) malloc((sizeof(Character) + sizeof(Character*))* N_CHARACTERS ); //setting the pointer eq to a pointer
  // Hint: You've been passed in a pointer to the location
  //       where we want to have an array's worth of memory.
  //       If this is wrinkling your brain this stackoverflow
  //       post may have some very valuable advice:
  //       https://stackoverflow.com/questions/897366/how-do-pointer-to-pointers-work-in-c-and-when-might-you-use-them
  //
}

// Applies the given move to all characters
// Note: 0 = Up, 1 = Down, 2 = Left, 3 = Right
void apply_moves(Character* characters, int move){
  //printf("Move: %d", move);
  //printf("   1: %d, ", characters[0].y);
  //printf("2: %d |||| ", characters[1].y);
  // loop through characters and create an array of numbers
  for (int i = 0; i < N_CHARACTERS; i++){
      if(move == 0 && (characters + i)->alive == 1){
          if((characters + i)->y == xy_max){
              continue;
          }else{
              (characters + i)->y++;
          }  
      }
      else if(move == 1 && (characters + i)->alive == 1){
          if((characters + i)->y == xy_min){
              continue;
          }else{
              (characters + i)->y--;
          }  
      }
      else if(move == 2 && (characters + i)->alive == 1){
          if((characters + i)->x == xy_min){
              continue;
          }else{
              (characters + i)->x--;
          }  
      }else{
          if((characters + i)->alive == 1){
              
              if((characters + i)->x == xy_max){
                  continue;
              }else{
                  (characters + i)->x++;
              }    
          }
      }
}
  //printf("After move.");
  //printf("1: %d, ", characters[0].y);
  //printf("2: %d\n", characters[1].y);
  //return characters;
}

// returns True if in collision
bool in_collision(Character& c1, Character& c2){
  //#TODO#
  //hint: the euclidean_distance function will be helpful and don't
  //forget characters are circles!
    
    float dist = euclidean_distance(c1.x, c1.y, c2.x, c2.y);
    //printf("\n %f \n", dist);
    if(dist < float(c1.size + c2.size)){
        return true;
    }
    return false;
}

// resolve a collision between two characters
void resolve_collision(Character& c1, Character& c2){
  // #TODO# 
  //printf("got here");
  // hint: make sure to break ties correctly!
    int size_offset = c1.size - c2.size;
    if(size_offset > 0){
        c2.alive = 0;
        c1.size += c2.size;  
        c2.size = 0;
    }
    else if(size_offset < 0){
        c1.alive = 0;
        c2.size+=c1.size;
        c1.size = 0; 
    }else{
        if(c1.id < c2.id){
            c2.alive=0;
            c1.size+=c2.size;
            c2.size = 0;
        
        }else{
            c1.alive =0;
            c2.size += c1.size;
            c1.size = 0;
        }
    }
  //return;
}

// check for and resolve all possible collisions
void check_resolve_all_collision(Character* characters){
  //
  // #TODO#
  // Hint: a modified version of the following code will be helpful
  //       when called correctly inside of some loops and conditionals 
   
    for(int i = 0; i < N_CHARACTERS; i++){
        for(int j = 0; j < N_CHARACTERS; j++){
            if( i != j && characters[i].alive == 1 && characters[j].alive==1 && in_collision(characters[i],characters[j])){
                resolve_collision(characters[i],characters[j]);
                
            } 
        }
    }
        
}
