# ComputerGraphics_Programs
It contains interesting graphics programs, implemented using graphics.h in C++

#### First graphics.h must be set up in your system (code::blocks recommended)!

Follow these steps:
1. Uninstall the previous code::blocks
2. Also don't forget to delete the CodeBlocks folder from appdata ("C:\Users\username\AppData\Roaming\CodeBlocks")
3. Install the new code::blocks from the link https://sourceforge.net/projects/codeblocks/?source=top3_dlp_t5 (updated)
4. Download graphics.h files from [here](http://www.mediafire.com/file/kmkx12ikip1rmft/C%2B%2B_Graphics.rar)
5. Copy 'graphics.h' & 'winbgim.h' to the folder "C:\Program Files (x86)\CodeBlocks\MinGW\include" and 'libbgi.a' to "C:\Program Files (x86)\CodeBlocks\MinGW\lib"
6. Open CodeBlocks : Settings -> Compiler

    #### Compiler settings tab
    
    a. Enable c++ 11
    
    #### Linker settings tab
    
    a. Add "C:\Program Files (x86)\CodeBlocks\MinGW\lib\libbgi.a" in 'Link libraries'
    
    b. Add in 'Other Linker Options':
    
        -lbgi
        
        -lgdi32
        
        -lcomdlg32
        
        -luuid
        
        -loleaut32
        
        -lole32
7. Press OK to exit
8. Now graphics.h can work with latest c++11 features also
