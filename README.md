# Notes

> All the tinyxml2 code is in the `tinyxml2` folder
> All the data is in the `data/store.xml`
> All our source code is in `src` folder

# How to run

# For Windows
> Drag and drop store file in Visual studio code.

> In terminal choose "New command prompt"

> To change directory to programs execcute below in the command prompt
    
    cd src

    Open a terminal and go to the `src` folder
    
> To compile the whole thing from the `src` folder execute

    g++ StoreCLI.cpp Store.cpp Product.cpp UniqueRandomNumberGenerator.cpp Utils.cpp ..\tinyxml2\tinyxml2.cpp -o storecli

Now you'll see the new file in the `src` folder named `storecli.exe`

> To show products

    > To show all products execute

        storecli.exe show

> To add a product execute

    storecli.exe add name="Tasty Chicken" price="7" description="Best chicken in the world" image_url="https://imgs.com/chicken"

    Once you execute this, you'll see the product in store.xml with a unique and random id


> To edit a product with an id

    storecli.exe edit id="1779" name="Edited" price="10" description="You have edited"

    Pass any properties you want to edit for that particular product and it will be updated in `data/store.xml`


> To remove a product execute

    storecli.exe remove id="1184"

    Use the id from the store.xml of the product to remove that particular product

>  To search particular product

    To show the product with an id

        storecli.exe show id="1819"

    > To show all products containing a search term like "chicken"

        storecli.exe show part_name="Eggs"

# For Linux

Drag and drop store file in Visual studio code.


> To change directory to programs execcute below in the command prompt
    
    cd src

    Open a terminal and go to the `src` folder
    
> To compile the whole thing from the `src` folder execute

    g++ StoreCLI.cpp Store.cpp Product.cpp UniqueRandomNumberGenerator.cpp Utils.cpp ../tinyxml2/tinyxml2.cpp -o storecli

> To run just execute the below in the command prompt

    ./storecli


> To show products

    > To show all products execute

        ./storecli show


> To add a product execute

    ./storecli add name="Tasty Chicken" price="7" description="Best chicken in the world" image_url="https://imgs.com/chicken"

    Once you execute this, you'll see the product in store.xml with a unique and random id


> To edit a product with an id

    ./storecli edit id="1779" name="Edited" price="10" description="You have edited"

    Pass any properties you want to edit for that particular product and it will be updated in `data/store.xml`


> To remove a product execute

    ./storecli remove id="1184"

    Use the id from the store.xml of the product to remove that particular product

>  To search particular product

    To show the product with an id

        ./storecli show id="1819"

    > To show all products containing a search term like "chicken"

        ./storecli show part_name="Eggs"