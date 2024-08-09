#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
std::vector<uint8_t> readRaw(const std::string filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if(!file.good()) printf("error #1");
    std::vector<uint8_t> bytes = std::vector<uint8_t>( std::istreambuf_iterator<char>( file ), {} );
    return bytes;
    
}
DWORD64 containsPattern(const std::vector<uint8_t>& bytes, const std::vector<uint8_t>& pattern) {
 auto it = std::search(bytes.begin(), bytes.end(), pattern.begin(), pattern.end());
    return static_cast<DWORD64>(it != bytes.end());
}
DWORD64 getNextToMemAddress(DWORD64 pMEM, uint8_t nextAddress) {
  if(pMEM + nextAddress) return pMEM + nextAddress;
  return;


}
int main() {
    int protectionLevel = 0;

    std::string filePath = "program.bin";
   std::vector<uint8_t> bytes = readRaw(filePath);
   if(bytes.empty()) {
    printf("error #2");
   }
   else {
    
    for(size_t i = 0; i<bytes.size() && i < 64; i++) {
       
       if (i % 16 == 0) std::cout << std::endl;
       std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << " ";
       

    }//headers
    std::cout << std::endl;
   }
   
  std::vector<uint8_t> main = {0x55, 0x8B, 0xEC, 0x83, 0xE4, 0xF8, 0x83, 0xEC, 0x0C, 0x56, 0x6A, 0x00
};

  if(containsPattern(bytes, main)) {
    std::cout << "Main Function Found" << std::endl;
    
  }//program.bin signatures

}
