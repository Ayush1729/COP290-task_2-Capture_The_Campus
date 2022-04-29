
SDL_Texture* loadTexture(char* path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        std::cout<<"Unable to load image ! SDL_image Error: "<< IMG_GetError();
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            std::cout<<"Unable to create texture from! SDL Error: "<< SDL_GetError() ;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
        loadedSurface = NULL;
    }

    return newTexture;
}




bool loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture
    //free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        std::cout<<"Unable to render text surface! SDL_ttf Error: "<<TTF_GetError()<<std::endl;
    }
    else
    {
        //Create texture from surface pixels
        gTextTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( gTextTexture == NULL )
        {
            std::cout<<"Unable to create texture from rendered text! SDL Error: "<< SDL_GetError()<<std::endl;
        }
        /*else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }*/

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return gTextTexture != NULL;
}



bool loadMedia()
{

    //Load PNG texture
    gTexture =  loadTexture("Graphics/background.jpg");
    gTexture2 =  loadTexture("Graphics/wallpaper.jpg");
    gTexture3 = loadTexture("Graphics/wolf.png");
    gTexture4 =  loadTexture("Graphics/Title.png");
    gTexture5 =  loadTexture("Graphics/iitd-campus.png");
    gTexture_blue_fire =  loadTexture("Graphics/Blue_Fire.png");
    gTexture_blue_wall =  loadTexture("Graphics/Blue_Wall.jpg");
    gTexture_red_wall =  loadTexture("Graphics/Red_Wall.jpg");
    gTexture_red_fire =  loadTexture("Graphics/Red_Fire.png");
    gTexture_emp =  loadTexture("Graphics/Purple_Orb.png");
    gTexture_shield =  loadTexture("Graphics/Green_Orb.png");
    gTexture_blue_acid =  loadTexture("Graphics/Blue_Acid.png");
    gTexture_red_acid =  loadTexture("Graphics/Red_Acid.png");




    if( gTexture == NULL or gTexture2 == NULL or gTexture3 == NULL or gTexture4 == NULL or gTexture5 == NULL)
    {
        std::cout<<"Failed to load texture image!\n";
        error_occ = true;
    }


    //Open the font
    gFont = TTF_OpenFont( "16_true_type_fonts/lazy.ttf", 28 );

    return error_occ;    
}
