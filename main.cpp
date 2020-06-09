#include <iostream>
#include <string>



int main(){

    std::string grid{"..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.."};

    for (int i = 0; i < grid.length(); i++)
    {
        std::cout << grid[i] << std::endl;
    }
    
    /** Initialize unsolved sudoku **/
    /** eg: "..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.." **/
    /** ## initialize rows and column ## **/
    /** # create Boxes key eg, [A1,A2, ... , I9] # **/
    /** # Generate Row Units eg, [A1,A2 ... A9] # **/
    /** # Generate Column Units eg, [A1,B1 ... I1] # **/
    /** # Generate Square Units eg, [A1,A2 ... C3] # **/
    /** # Generate peers # **/


      /** ### --- Create Board --- ### **/
    /** ## --- Grid, grid is unsolved sudoku string---  Assign Value To Boxes, eg: [A1:9 , A2:2 ...]## **/
    /** first add all possible values as value of box eg ; A1 : 12345789 **/
            // if value is . then append all values [12346789] otherwise remaining values 
    /** # Check the length of grid is 81 else throw error # **/
    /** # --- Display Board -- # **/
    /** Returns Grid Values , A1:13245678,A2:8 **/


    /**  ----------------------- Eliminate Strategy -----------------------------------------------**/
    /** Go through All boxes , Where there is a box with single value eliminate that from set of values of all its peers **/
    /** input is values from grid , **/
    /** return eliminated values **/

    /**  ----------------------- Only Choice Strategy -----------------------------------------------**/
    /** Go through All boxes ,  **/
    /** input is values from grid , **/
    /** return eliminated values **/

    /**  ----------------------- Constrain Propagation -----------------------------------------------**/
    /** use strategy elimination and only choice repeatedly **/
    /** stop if there is no editabel value **/
    /** if  solved values sames after two iteration then stop it **/
    /** Input : Values **/
    /** Outpu Solved Values **/


    
    return 0;
}