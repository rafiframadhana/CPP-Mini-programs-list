#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int, int> hashTable;
  int n;
  cout << "Enter the number of key-value pairs to be inserted: ";
  cin >> n;

  int key, value;
  for (int i = 0; i < n; i++) {
    cout << "Enter key-value pair " << i + 1 << ": ";
    cin >> key >> value;
    hashTable[key] = value;
  }

  cout << "Hash table contains the following key-value pairs: " << endl;
  for (auto it = hashTable.begin(); it != hashTable.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  return 0;
}