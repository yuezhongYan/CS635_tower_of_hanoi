# include<iostream>
using namespace std;

bool IsValid(char* array);
int ObtainArrayLength(char* array);
void tgen(int n, char* i, char* f);
char* ToUppercase(char* array);

/* The number of pegs starting with A.
 * 
 * For example, 
 * if it is 3, then the pegs are A, B, C.
 * We can hard-code this constant with 4.
 * If it is 4, then the pegs are A, B, C, D.
 */
const int g_NUMBER_OF_PEGS = 3;

bool IsValid(char* array){
    bool is_valid_array = true;
    int j = 0;
    while (array[j]){
        if(array[j] < 65 ||
           (array[j] > 64 + g_NUMBER_OF_PEGS && array[j] < 97) ||
           array[j] > 96 + g_NUMBER_OF_PEGS){
            is_valid_array = false;
            break;
        }
        j++;
    }
    return is_valid_array;
}

int main(){
    int total_number_of_disks = 0;
    char* initial_configuration = new char[total_number_of_disks];
    char* final_configuration = new char[total_number_of_disks];

    cout << "Enter total number of disks: " << endl;
    cin >> total_number_of_disks;
    cout << "Enter initial configuration: " << endl;
    cin >> initial_configuration;
    cout << "Enter final configuration: " << endl;
    cin >> final_configuration;
    
    int initial_configuration_size = ObtainArrayLength(initial_configuration);
    int final_configuration_size = ObtainArrayLength(final_configuration);

    if (initial_configuration_size != total_number_of_disks ||
        final_configuration_size != total_number_of_disks){
            cout << "Input configuration length"
                    " does not match total number of disks" << endl;
            return 0;
    }

    bool is_valid_input = (total_number_of_disks >= 0) &&
                          IsValid(initial_configuration) &&
                          IsValid(final_configuration);

    if(!is_valid_input){
        cout << "Invalid input. Valid total number of disks and ranges of letters"
                " are expected" << endl;
        return 0;
    }

    initial_configuration = ToUppercase(initial_configuration);
    final_configuration = ToUppercase(final_configuration);

    tgen(total_number_of_disks, initial_configuration, final_configuration);
    return 0;
}

int ObtainArrayLength(char* array){
    int array_size = 0;
    while (array[array_size]){
        array_size++;
    }
    return array_size;
}

void tgen(int n, char* i, char* f){
    if(n == 0){
        return;
    }

    if(n == 1){
        if(i[0] != f[0]){
            cout << "Move " << i[0] << " to " << f[0] << endl;
        }
    }else{
        /*
         * if the big disk is on the same tower in both initial and final configurations,
         * ignore the big disk and solve the problem for the n – 1 remaining disks.
         */
        if(i[0] == f[0]){
            tgen(n - 1, i + 1, f + 1);
        }else{
            char other_tower = 'A' + g_NUMBER_OF_PEGS - (i[0] - 'A' + f[0] - 'A');
            char* auxiliary_configuration = new char[n - 1];

            for(int j = 0; j < n - 1; j++){
                auxiliary_configuration[j] = other_tower;
            }

            /* Ignoring the biggest disk, move all the other disks onto the other tower. */
            tgen(n - 1, i + 1, auxiliary_configuration);

            /* Move the big disk to the tower it belongs on in the final configuration. */
            cout << "Move " << i[0] << " to " << f[0] << endl;

            /* 
             * Ignoring the biggest disk, move all the other disks onto the towers they
             * belong on. 
             */
            tgen(n - 1, auxiliary_configuration, f + 1);
        }
    }
}

char* ToUppercase(char* array){
    int j = 0;
    while(array[j] != '\0'){
        if(array[j] >= 97 && array[j] <= 96 + g_NUMBER_OF_PEGS){
		    array[j] = array[j] - 32;
        }
        j++;
    }
    return array;
}
