#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> Cross(string rows, string cols){

    vector<string> cross_product;

    for (int i = 0; i < rows.length(); i++)
    {
        for (int j = 0; j < cols.length(); j++)
        {
            auto val = string{rows[i]}+string{cols[j]};
            cout << val;
            cross_product.push_back(val);
        }
        cout << endl;
        
       
    }

    return cross_product;
    

}

int main(){

    /** Initialize unsolved sudoku **/
    /** eg: "..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.." **/
    string grid{"..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.."};
    
    /** ## initialize rows and column ## **/
    char rows[]="ABCDEFGHI";
    char cols[] ="123456789";

    /** # create Boxes key eg, [A1,A2, ... , I9] # **/
    vector<string> boxes = Cross(rows,cols);
    cout << boxes.size() << endl;


    /** # Generate Row Units eg, [A1,A2 ... A9] # **/
    vector<vector<string>> row_units;
    for (int i = 0; i < sizeof(rows)-1; i++)
    {
       row_units.push_back(Cross(string{rows[i]},cols));
    }
    
    cout << row_units.size() << endl;
    
    
    /** # Generate Column Units eg, [A1,B1 ... I1] # **/
    vector<vector<string>> col_units;

    for (int i = 0; i < sizeof(cols)-1; i++)
    {
        col_units.push_back(Cross(rows,string{cols[i]}));
    }
    cout << col_units.size() << endl;
    
    /** # Generate Square Units eg, [A1,A2 ... C3] # **/
    
    string rows_by_3[] ={"ABC","DEF","GHI"};
    string cols_by_3[] ={"123","456","789"};

    vector<vector<string>> square_units;

    for (int i = 0; i < 3; i++)
    {
        for (int m = 0; m < 3; m++)
        {
           auto result =  Cross(rows_by_3[i],cols_by_3[m]);
           square_units.push_back(result);
        }
        
    }
    cout << square_units.size() << endl;
    vector<vector<vector<string>>> unit_list{row_units,col_units,square_units};
    cout << "size of unit list is : " << unit_list.size() << endl;

    for(vector<vector<string>> unit: unit_list){
        cout << "size of units are : " << unit.size() << endl;
    }
    
    
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