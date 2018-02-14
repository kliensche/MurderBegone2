// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGameInstance.h"
#include "Runtime/MoviePlayer/Public/MoviePlayer.h"
//#include "Engine/World.h"

void UBaseGameInstance::Init()
{
	UGameInstance::Init();
	bStartupMoviesPlayed = false;

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UBaseGameInstance::BeginLoadingScreen);
	//FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UBaseGameInstance::EndLoadingScreen);
}

void UBaseGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		//UE_LOG(LogTemp, Warning, TEXT("MapName: %s"), *MapName);
		if (!bStartupMoviesPlayed)
		{
			LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;

			//add every single video
			//LoadingScreen.MoviePaths.Add("UE4_Logo_test");
			LoadingScreen.MoviePaths.Add("GALogoAnim");

			//or all videos from one array
			//LoadingScreen.MoviePaths.Append(/*from any array*/);
			bStartupMoviesPlayed = true;
		}
		//else
		//{
		//	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		//	LoadingScreen.MinimumLoadingScreenDisplayTime = 5.0f;
		//	LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		//}

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

// void UBaseGameInstance::EndLoadingScreen(UWorld* world)
// {
// 
// }
