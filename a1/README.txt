Name: Xinwei Lin
ONID: 933332253

Description:
    My code takes three command line arguments, first one, of courese, is the ./catalog_prog,
    the second is the name of file that has all wizards information. The third is the name of 
    the file that has all information about spell books.
    The program will ask you to login with your id and password.
    Once you logged in, you can type 1-4 to select an sorting option to see spells that you want.
    You can also select to print those spells to file with the name you choose.

Instructions:
    use make to compile my code:
        make
    run my code:
        ./catalog_prog file_name1 file_name2

Limitations:
    My program handles most of the errors, but if user inputs things like '4u', my code will consider it 
    as integer '4'. And my code won't stop because of that.

