// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FindSessionsCallbackProxy.h"
#include "SessionSubSystem.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EBPOnJoinSessionCompleteResult : uint8
{
	Success,
	SessionIsFull,
	SessionDoesNotExist,
	CouldNotRetrieveAddress,
	AlreadyInSession,
	UnknownError
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnCreateSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnUpdateSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnStartSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnEndSessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnDestroySessionComplete, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCourseOnFindSessionsComplete, const TArray<FBlueprintSessionResult>&, SessionResults, bool, Successful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCourseOnJoinSessionComplete, EBPOnJoinSessionCompleteResult, Result);

UCLASS()
class MYPROJECT_API USessionSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	USessionSubSystem();
	
	UFUNCTION(BlueprintCallable) void CreateSession(int32 NumPublicConnections, bool bIsLANMatch);
	UFUNCTION(BlueprintCallable) void UpdateSession();
	UFUNCTION(BlueprintCallable) void StartSession();
	UFUNCTION(BlueprintCallable) void EndSession();
	UFUNCTION(BlueprintCallable) void DestroySession();
	UFUNCTION(BlueprintCallable) void FindSessions(int32 MaxSearchResults, bool bIsLANQuery);
	UFUNCTION(BlueprintCallable) void JoinGameSession(const FBlueprintSessionResult& SessionResult);
	
	UPROPERTY(BlueprintAssignable) FCourseOnCreateSessionComplete OnCreateSessionCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnUpdateSessionComplete OnUpdateSessionCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnStartSessionComplete OnStartSessionCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnEndSessionComplete OnEndSessionCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnDestroySessionComplete OnDestroySessionCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnFindSessionsComplete OnFindSessionsCompleteEvent;
	UPROPERTY(BlueprintAssignable) FCourseOnJoinSessionComplete OnJoinGameSessionCompleteEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere) TSoftObjectPtr<UWorld> Level;
	
protected:
	void OnCreateSessionCompleted(FName SessionName, bool Successful);
	void OnUpdateSessionCompleted(FName SessionName, bool Successful);
	void OnStartSessionCompleted(FName SessionName, bool Successful);
	void OnEndSessionCompleted(FName SessionName, bool Successful);
	void OnDestroySessionCompleted(FName SessionName, bool Successful);
	void OnFindSessionsCompleted(bool Successful);
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	bool TryTravelToCurrentSession();
	
private:
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;
	
	FOnUpdateSessionCompleteDelegate UpdateSessionCompleteDelegate;
	FDelegateHandle UpdateSessionCompleteDelegateHandle;
	
	FOnStartSessionCompleteDelegate StartSessionCompleteDelegate;
	FDelegateHandle StartSessionCompleteDelegateHandle;
	
	FOnEndSessionCompleteDelegate EndSessionCompleteDelegate;
	FDelegateHandle EndSessionCompleteDelegateHandle;
	
	FOnDestroySessionCompleteDelegate DestroySessionCompleteDelegate;
	FDelegateHandle DestroySessionCompleteDelegateHandle;
	
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;
	FDelegateHandle FindSessionsCompleteDelegateHandle;
	TSharedPtr<FOnlineSessionSearch> LastSessionSearch;
	
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
	FDelegateHandle JoinSessionCompleteDelegateHandle;
};
