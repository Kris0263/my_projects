#include "splashkit.h"
#include <string>
#include <vector>

using namespace std;

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

struct knight_data
{
    string name;
    string last_name;
    string birth_month;
    int age;
    vector<string> tools;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};

void add_tool(knight_data& knight)
{
    knight.tools.push_back(read_string("Enter tool: "));
}


int select_knight(const kingdom_data& kingdom)
{
    int result = -1;
    if (kingdom.knights.empty())
    {
        write_line("No knights available.");
        return result;
    }
    write_line("Select a knight:");
    for (int i = 0; i < kingdom.knights.size(); i++)
    {
        write_line(to_string(i + 1) + ": " + kingdom.knights[i].name + " " + kingdom.knights[i].last_name);
    }

    int selected_knight = read_integer("Enter knight number (0 to cancel): ");
    if (selected_knight > 0 && selected_knight <= kingdom.knights.size())
    {
        result = selected_knight - 1;
    }
    return result;
}

knight_data read_knight()
{
    knight_data result;

    write_line("");
    result.name = read_string("Enter name: ");
    result.last_name = read_string("Enter last name: ");
    result.birth_month = read_string("Enter month of birth: ");
    result.age = read_integer("Enter age: ");
    int tools;
    tools = read_integer("Enter number of tools: ");
    for (int i = 0; i < tools; i++)
    {
        add_tool(result);
    }

    return result;
}


void write_knight(const knight_data& knight)
{
    write_line(knight.name + " " + knight.last_name + " aged " + to_string(knight.age) + " born in " + knight.birth_month + " month. It's my honor to meet you.");
    if (!knight.tools.empty())
    {
        write_line("Tools:");
        for (int i = 0; i < knight.tools.size(); i++)
        {
            write_line("- " + knight.tools[i]);
        }
    }
}

void write_kingdom(const kingdom_data& kingdom)
{
    write_line("=================");
    write_line(kingdom.name);
    write_line("==== Knights ====");
    for (int i = 0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("==================");
}

void add_knight( kingdom_data &kingdom)
{
    knight_data new_knight;
    new_knight = read_knight();
    kingdom.knights.push_back(new_knight);
}

void delete_knight(kingdom_data& kingdom, int index)
{
    if (index >= 0 && index < kingdom.knights.size())
    {
        kingdom.knights.erase(kingdom.knights.begin() + index);
    }
}

kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter Kingdom Name: ");
    return result;
}

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_LAST_NAME,
    UPDATE_BIRTH_MONTH,
    UPDATE_AGE,
    UPDATE_TOOL,
    END_UPDATE,
};

enum kingdom_upadte_option 
{
    ADD_KNIGHT,
    UPDATE_KNIGHT,
    QUERY_KNIGHT,
    DELETE_KNIGHT, 
    DISPLAY_KNIGDOM_DATA,
    FINISH_UPDATE 
};

knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update last name");
    write_line("3: Update birth month");
    write_line("4: Update age");
    write_line("5: Update tools");
    write_line("6: End update");
    result = read_integer("Select Option: ");

    return static_cast<knight_update_option>(result - 1);
}

kingdom_upadte_option read_kingdom_update_option()
{
    int result;
    write_line("1: Add knight ");
    write_line("2: Update knight ");   
    write_line("3: Query knight ");
    write_line("4: Delete knight ");
    write_line("5: Display kingdom data ");
    write_line("6: Finish Update ");
    write_line("");
    result = read_integer("Select Option: ");
    
    return static_cast <kingdom_upadte_option>(result - 1); 
}


enum tools_update_option
{
    ADD_TOOLS,
    DELETE_TOOLS,
    QUIT
};

int select_tool(const knight_data& knight)
{
    int result = -1;
    if (knight.tools.empty())
    {
        write_line("No tools available.");
        return result;
    }
    write_line("Select a tool:");
    for (int i = 0; i < knight.tools.size(); i++)
    {
        write_line(to_string(i + 1) + ": " + knight.tools[i]);
    }

    int selected_tool = read_integer("Enter tool number (0 to cancel): ");
    if (selected_tool > 0 && selected_tool <= knight.tools.size())
    {
        result = selected_tool - 1;
    }
    return result;
}

void delete_tool(knight_data& knight, int index)
{
    if (index >= 0 && index < knight.tools.size())
    {
        knight.tools.erase(knight.tools.begin() + index);
    }
}





tools_update_option read_tools_update_option()
{
    int result;
    write_line("1: Add tool ");
    write_line("2: Delete tool ");   
    write_line("6: Finish Update ");
    write_line("");
    result = read_integer("Select Option: ");
    
    return static_cast <tools_update_option>(result - 1); 
}





void update_tools(knight_data &knight)
{
    tools_update_option option;
    do
    {
        write_line();
        write_line("==Update tools ==");
        write_knight(knight);
        write_line();
        write_line("Select an option to update:");

        option = read_tools_update_option();

        switch(option)
        {
            case ADD_TOOLS:
                add_tool(knight);
                break;
            case DELETE_TOOLS:
                int index;
                index = select_tool(knight);
                delete_tool(knight,index);
                break;

            case QUIT:
                break;
            default:
                write_line("Please select a valid option.");
        }

    } while ( option != QUIT );
}


void update_knight(knight_data &knight)
{
    knight_update_option option;
    do
    {
        write_line();
        write_line("==Update Knight ==");
        write_knight(knight);
        write_line();
        write_line("Select an option to update:");

        option = read_knight_update_option();

        switch(option)
        {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name: ");
                break;
            case UPDATE_LAST_NAME:
                knight.last_name = read_string("Enter new last name: ");
                break;
            case UPDATE_BIRTH_MONTH:
                knight.birth_month = read_string("Enter new birth month: ");
                break;
            case UPDATE_AGE:
                knight.age = read_integer("Enter new age: ");
                break;
            case UPDATE_TOOL:
                update_tools(knight); 
                break;
            case END_UPDATE:
                break;
            default:
                write_line("Please select a valid option.");
        }

    } while ( option != END_UPDATE );
}

void update_kingdom(kingdom_data &kingdom)
{
    kingdom_upadte_option option; 

    do     
    {
        write_line();
        write_line ("=== UPDATE KINGDOM ===");
        write_line();

        option = read_kingdom_update_option();

        switch(option) 
        {
            case ADD_KNIGHT: 
                add_knight(kingdom);
                break;
            case UPDATE_KNIGHT: 
                update_knight(kingdom.knights[select_knight(kingdom)]);            
                break;
            case QUERY_KNIGHT: 
                write_line();
                int knight_index;
                knight_index = select_knight(kingdom);
                if(knight_index >= 0 and knight_index < kingdom.knights.size())
                {
                    write_line("");
                    write_line("===selected knight's data===");
                    write_knight(kingdom.knights[knight_index]);     
                }
                else 
                {
                    write_line("*** invalid ***");
    
                }
                break;
            case DELETE_KNIGHT:
                write_line();
                int index;
                index = select_knight(kingdom);
                delete_knight(kingdom,index);
                break;
            case DISPLAY_KNIGDOM_DATA: 
                write_kingdom(kingdom);
                break;
            case FINISH_UPDATE: 
                break;
            default:    
                write_line("Please select a valid option");
        }
    } while (option != FINISH_UPDATE);  
}



int main()
{

    kingdom_data my_kingdom;
    
    write_line("");

    my_kingdom = read_kingdom();

    int number_of_knights;

    write_line("");

    number_of_knights = read_integer("How many knights you want in the kingdom: ");

    for (int i=0; i < number_of_knights; i++ )

    {
        add_knight(my_kingdom);
    }


    update_kingdom(my_kingdom);


    return 0;
}
