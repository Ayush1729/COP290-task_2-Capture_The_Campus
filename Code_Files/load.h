
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




bool loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font* Font)
{
    //Get rid of preexisting texture
    //free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( Font, textureText.c_str(), textColor );
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
    gTexture2 =  loadTexture("Graphics/background-instructions-2.png");
    gTexture3 = loadTexture("Graphics/wolf.png");
    gTexture4 =  loadTexture("Graphics/Title.png");
    gTexture5 =  loadTexture("Graphics/iitd-campus.png");
    gTexture_blue_fire =  loadTexture("Graphics/Blue_Fire.png");
    gTexture_blue_wall =  loadTexture("Graphics/Blue_Wall.jpeg");
    gTexture_red_wall =  loadTexture("Graphics/Red_Wall.jpg");
    gTexture_red_fire =  loadTexture("Graphics/Red_Fire.png");
    gTexture_emp =  loadTexture("Graphics/Purple_Orb.png");
    gTexture_shield =  loadTexture("Graphics/Green_Orb.png");
    gTexture_blue_acid =  loadTexture("Graphics/Blue_Acid.png");
    gTexture_red_acid =  loadTexture("Graphics/Red_Acid.png");
    gTexture_freeze =  loadTexture("Graphics/freeze.png");
    gSelect_image = loadTexture("Graphics/select.png");
    gTexture_instructions_text = loadTexture("Graphics/Instructions_text.png" );
    gTexture_powers_text = loadTexture("Graphics/Powers_text.png");


    gTexture_fire_button =  loadTexture("Graphics/fire_button.jpeg");
    gTexture_wall_button =  loadTexture("Graphics/wall_button.jpg");
    gTexture_acid_button =  loadTexture("Graphics/acid_button.jpeg");
    gTexture_emp_button = loadTexture("Graphics/emp_button.jpeg");
    gTexture_shield_button = loadTexture("Graphics/shield_button.jpeg" );
    gTexture_freeze_button = loadTexture("Graphics/freeze_button.jpeg");


    if( gTexture == NULL or gTexture2 == NULL or gTexture3 == NULL or gTexture4 == NULL or gTexture5 == NULL){
        std::cout<<"Failed to load texture image!"<<endl;
        error_occ = true;
    }

    // setting up transparency

    SDL_SetTextureBlendMode( gSelect_image, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gSelect_image, 96 );

    SDL_SetTextureBlendMode( gTexture_freeze, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gTexture_freeze, 128 );

    SDL_SetTextureBlendMode( gTexture_blue_acid, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gTexture_blue_acid, 128 );

    SDL_SetTextureBlendMode( gTexture_shield, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gTexture_shield, 128 );

    SDL_SetTextureBlendMode( gTexture_blue_fire, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gTexture_blue_fire, 128 );

    SDL_SetTextureBlendMode( gTexture_emp, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod( gTexture_emp, 128 );




    gflappy = TTF_OpenFont( "fonts/flappy.ttf", 28 );
    gaerobusdotty = TTF_OpenFont("fonts/aerobusdotty.ttf", 50);
    gPacifico = TTF_OpenFont("fonts/Roboto-BoldItalic.ttf", 50);

    if( (gflappy == NULL) or (gaerobusdotty == NULL) or (gPacifico == NULL) ){
        std::cout<<"Failed to load font! SDL_ttf Error: "<< TTF_GetError()<<std::endl;
        error_occ = true;
    }








    //Load music
    gMusic = Mix_LoadMUS( "Audio/music.wav" );
    gPlay_Music = Mix_LoadMUS("Audio/play_music.wav");
    
    //Load sound effects
    gbegin_sound = Mix_LoadWAV( "Audio/gametime.wav" );
    gSelect_sound = Mix_LoadWAV( "Audio/brick-hit-2.wav" );
    gVictory_sound = Mix_LoadWAV( "Audio/victory.wav" );
    gLow = Mix_LoadWAV( "Audio/explosion.wav" );

    if(( gMusic == NULL ) or (gbegin_sound == NULL) or (gSelect_sound == NULL) or (gVictory_sound == NULL) or (gLow == NULL) or (gPlay_Music == NULL) ) {
        std::cout<<"Failed to load audio! SDL_mixer Error: "<< Mix_GetError()<< endl;
        error_occ = true;
    }



    

    return error_occ;    
}
