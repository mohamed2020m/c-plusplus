#include<iostream>
#include<vector>

using namespace std;

bool even(int);
int num_of_even(int*, int l);

int main(){
    vector<vector<int>> all_max_even_arrs, arr;
    int vector_length, number; 

    cout << "What's the length of the vector ? ";
    cin >> vector_length;

    cout << "Enter " <<  vector_length << " rows containing space-separeted integers only, to construct a matrix of " << vector_length << "x" << vector_length << endl;
    
    for(int i = 0; i < vector_length; i++){
        vector<int> temp;
        for(int j = 0; j < vector_length; j++){
            cin >> number;
            temp.push_back(number);
        }
        arr.push_back(temp);
        temp.clear();
    }

    vector<int> max_even_arr = arr[0];
    int even_max = num_of_even(arr[0].data(), arr[0].size());

    for(int i = 1; i < arr.size(); i++){
        int sum_even = num_of_even(arr[i].data(), arr[i].size());
        if(sum_even >= even_max){
            max_even_arr.assign(arr[i].data(), arr[i].data() + arr[i].size());
            if(sum_even != even_max){
                all_max_even_arrs.clear();
            }
            all_max_even_arrs.push_back(max_even_arr);
            even_max = sum_even;
        }
    }


    if(all_max_even_arrs.size() >= 2){
        cout << "The rows that contains maximum number of even numbers are : " << endl;
        cout << "{";
        for(int j = 0; j < all_max_even_arrs.size(); j++){
            cout << "{";
            for(int i = 0; i < all_max_even_arrs[j].size() ; i++){
                cout << all_max_even_arrs[j][i];
                if(i != all_max_even_arrs[j].size() - 1){
                    cout << ", ";
                }
            }
            cout << "}";
            if(j != all_max_even_arrs.size() - 1){
                cout << ", ";
            }
        }
        cout << "}";
    }
    else{
        cout << "The row that contains maximum number of even numbers is : " << endl;
        cout << "{";
        for(int i = 0; i < max_even_arr.size() ; i++){
            cout << max_even_arr[i];
            if(i != max_even_arr.size() - 1){
                cout << ", ";
            }
        }
        cout << "}";
    }
    cout << endl;
    cout << "the maximu even numbers exist is : " << even_max << endl;
    return 0;
}


// checking if a num is even or odd
bool even(int num){
    if(num % 2 == 0){
        return true;
    }
    return false;
}

int num_of_even(int* arr, int l){
    int s = 0;
    for(int k = 0; k < l; k++){
        if(even(*(arr + k))){
            s++;
        }
    }
    return s;
}

