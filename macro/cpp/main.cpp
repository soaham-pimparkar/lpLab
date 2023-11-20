#include "macro_processor.cpp"

int main( int argc , char** argv ) {
    MacroProcessor macroProcessor( "testcase_02.txt" ) ;
    macroProcessor.perform() ; 
    return 0;
}