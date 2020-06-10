#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

vector<string> Cross(string rows, string cols)
{

    vector<string> cross_product;

    for (int i = 0; i < rows.length(); i++)
    {
        for (int j = 0; j < cols.length(); j++)
        {
            auto val = string{rows[i]} + string{cols[j]};
            // cout << val;
            cross_product.push_back(val);
        }
        // cout << endl;
    }

    return cross_product;
}

map<string, string> GenerateGrid(const vector<string> &boxes, const string &grid)
{

    /** # Check the length of grid is 81 else throw error # **/
    if (grid.length() != 81)
    {
        cout << "Invalid file Length " << endl;
    }
    map<string, string> grid_value;

    for (int i = 0; i < boxes.size(); i++)
    {
    

        if (grid[i] == '.')
        {
            grid_value[boxes[i]] = "123456789";
        }else{
        grid_value[boxes[i]] = grid[i];

        }
        
    }

    return grid_value;
}

map<string, string> EliminateGridValue(const vector<string> &boxes,
 map<string, string>& grid_values, map<string, set<string>>& peers)
{

    vector<pair<string,string>> single_values;
    for (string box : boxes)
    {
           for(auto i = grid_values.begin() ; i != grid_values.end(); i++)
           {
               if (i->second.length() == 1)
               {
                
                  single_values.push_back(make_pair(i->first, i->second));
               }
               
           }
    }
    
    for (int i = 0; i < single_values.size(); i++)
    {
        string key = single_values.at(i).first;
        string v = single_values.at(i).second;

        for(string peer : peers[key]){
            int pos = grid_values[peer].find(v);
            if (pos != -1)
            {
                grid_values[peer].replace(pos, 1,"");
            }
            
        }
    }
    

    return grid_values;
}


void OnlyChoice(const vector<string>& boxes, vector<vector<vector<string>>>& unit_list, map<string,string> grid_values)
{

}

void DisplayGrid(map<string, string> &grid)
{

    int count = 0;
    for (auto i = grid.begin(); i != grid.end(); i++)
    {
        /** first add all possible values as value of box eg ; A1 : 12345789 **/
        // if value is . then append all values [12346789] otherwise remaining values

        if (i->second == ".")
        {
            grid[i->first] = "123456789";
        }

        count++;
        cout << i->second << " ";
        if (count % 3 == 0)
        {
            cout << " | ";
        }
        if (count % 9 == 0)
        {
            cout << endl;
        }
        if (count % 27 == 0)
        {
            cout << endl;
        }
    }
}



int main()
{

    /** Initialize unsolved sudoku **/
    /** eg: "..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.." **/
    string grid{"..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3.."};

    /** ## initialize rows and column ## **/
    char rows[] = "ABCDEFGHI";
    char cols[] = "123456789";

    /** # create Boxes key eg, [A1,A2, ... , I9] # **/
    vector<string> boxes = Cross(rows, cols);
    cout << boxes.size() << endl;

    /** # Generate Row Units eg, [A1,A2 ... A9] # **/
    vector<vector<string>> row_units;
    for (int i = 0; i < sizeof(rows) - 1; i++)
    {
        row_units.push_back(Cross(string{rows[i]}, cols));
    }

    cout << row_units.size() << endl;

    /** # Generate Column Units eg, [A1,B1 ... I1] # **/
    vector<vector<string>> col_units;

    for (int i = 0; i < sizeof(cols) - 1; i++)
    {
        col_units.push_back(Cross(rows, string{cols[i]}));
    }
    cout << col_units.size() << endl;

    /** # Generate Square Units eg, [A1,A2 ... C3] # **/

    string rows_by_3[] = {"ABC", "DEF", "GHI"};
    string cols_by_3[] = {"123", "456", "789"};

    vector<vector<string>> square_units;

    for (int i = 0; i < 3; i++)
    {
        for (int m = 0; m < 3; m++)
        {
            auto result = Cross(rows_by_3[i], cols_by_3[m]);
            square_units.push_back(result);
        }
    }
    cout << square_units.size() << endl;
    vector<vector<vector<string>>> unit_list{row_units, col_units, square_units};
    cout << "size of unit list is : " << unit_list[0].size() << endl;

    map<string, vector<vector<string>>> units;

    for (string c : boxes)
    {
        vector<vector<string>> temp_unit;
        for (vector<vector<string>> unit : unit_list)
        {
            for (vector<string> u : unit)
            {
                if (find(u.begin(), u.end(), c) != u.end())
                {
                    temp_unit.push_back(u);
                    break;
                }
            }
           
        }

        units[c]=temp_unit;

    }


map<string, set<string>> peers;


 for (string c : boxes)
    {
        vector<string> data;
        for(vector<string> unit : units[c]){
            
            for(string s: unit){
                if (s != c)
                {
                    data.push_back(s);
                }
                
            }
            
        }

        set<string> updated;
        for(string se : data){
            updated.insert(se);
        }
        

        peers[c] = updated;

    }



    cout << "Size of each unit is " << units.at("A1").size() << endl;

    /** # Generate peers # **/

    /** ### --- Create Board --- ### **/
    /** ## --- Grid, grid is unsolved sudoku string---  Assign Value To Boxes, eg: [A1:9 , A2:2 ...]## **/
    /** Returns Grid Values , A1:13245678,A2:8 **/
    map<string, string> grid_values = GenerateGrid(boxes, grid);

    /** # --- Display Board -- # **/
    // DisplayGrid(grid_values);

    /**  ----------------------- Eliminate Strategy -----------------------------------------------**/
    /** Go through All boxes , Where there is a box with single value eliminate that from set of values of all its peers **/
    auto eliminated_values = EliminateGridValue(boxes, grid_values,peers);
    DisplayGrid(eliminated_values);
    /** input is values from grid , **/
    /** return eliminated values **/

    /**  ----------------------- Only Choice Strategy -----------------------------------------------**/
    /** Go through All boxes ,  **/
    OnlyChoice(boxes, unit_list,eliminated_values);
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