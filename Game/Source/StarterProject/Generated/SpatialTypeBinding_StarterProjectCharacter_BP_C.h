// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealStarterProjectCharacterBPC.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_StarterProjectCharacter_BP_C.generated.h"

UCLASS()
class USpatialTypeBinding_StarterProjectCharacter_BP_C : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FHandoverHandlePropertyMap& GetHandoverHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView(bool bIsClient) override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_StarterProjectCharacter_BP_C::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCNetMulticastRPCs::Update& Update);

	// RPC command sender functions.
	void TestClientRPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void RootMotionDebugClientPrintOnScreen_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVeryShortAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatWalk_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatGhost_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatFly_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionSourcePosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAckGoodMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void SetArrOfStructs1_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void SetArrOfStructs2_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void RPCStructInput_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void UpdateNestedStructCpp_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void UpdateNestedStructBP_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void TestRPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveOld_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualHybridRootMotion_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDual_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void TestMulticast_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void TestClientRPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>& Op);
	void RootMotionDebugClientPrintOnScreen_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op);
	void ClientVeryShortAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>& Op);
	void ClientCheatWalk_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>& Op);
	void ClientCheatGhost_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>& Op);
	void ClientCheatFly_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>& Op);
	void ClientAdjustRootMotionSourcePosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op);
	void ClientAdjustRootMotionPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>& Op);
	void ClientAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>& Op);
	void ClientAckGoodMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>& Op);
	void SetArrOfStructs1_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>& Op);
	void SetArrOfStructs2_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>& Op);
	void RPCStructInput_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>& Op);
	void UpdateNestedStructCpp_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>& Op);
	void UpdateNestedStructBP_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>& Op);
	void TestRPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>& Op);
	void ServerMoveOld_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>& Op);
	void ServerMoveNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>& Op);
	void ServerMoveDualNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>& Op);
	void ServerMoveDualHybridRootMotion_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>& Op);
	void ServerMoveDual_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>& Op);
	void ServerMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>& Op);
	void TestMulticast_OnRPCPayload(const worker::EntityId EntityId, const improbable::unreal::generated::starterprojectcharacter::TestMulticastRequest& EventData);

	// RPC command response handler functions.
	void TestClientRPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Testclientrpc>& Op);
	void RootMotionDebugClientPrintOnScreen_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op);
	void ClientVeryShortAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientveryshortadjustposition>& Op);
	void ClientCheatWalk_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatwalk>& Op);
	void ClientCheatGhost_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatghost>& Op);
	void ClientCheatFly_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientcheatfly>& Op);
	void ClientAdjustRootMotionSourcePosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op);
	void ClientAdjustRootMotionPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustrootmotionposition>& Op);
	void ClientAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientadjustposition>& Op);
	void ClientAckGoodMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCClientRPCs::Commands::Clientackgoodmove>& Op);
	void SetArrOfStructs1_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs1>& Op);
	void SetArrOfStructs2_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Setarrofstructs2>& Op);
	void RPCStructInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Rpcstructinput>& Op);
	void UpdateNestedStructCpp_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructcpp>& Op);
	void UpdateNestedStructBP_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Updatenestedstructbp>& Op);
	void TestRPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Testrpc>& Op);
	void ServerMoveOld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermoveold>& Op);
	void ServerMoveNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovenobase>& Op);
	void ServerMoveDualNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualnobase>& Op);
	void ServerMoveDualHybridRootMotion_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedualhybridrootmotion>& Op);
	void ServerMoveDual_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermovedual>& Op);
	void ServerMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::starterprojectcharacterbpc::StarterProjectCharacterBPCServerRPCs::Commands::Servermove>& Op);

	struct FMyStruct__pf3826073315
	{
		bool StructBool_1_76B6BADA4BA8FEA4761B938495DEA0E1;
		FVector StructVec_4_734F338F470A88C85C79289BBB7E8467;
	};

	struct FMyStructWithArray__pf3826073315
	{
		TArray<bool> MyBoolArrayNested_7_87D2B213446573EC06159DB37E89CD99;
		TArray<FMyStruct__pf3826073315> MyStructArrayNested_6_3B3D5A594BF31A5D239E52AF9AD0D3D7;
	};

	struct FMyStructLv2__pf3826073315
	{
		FMyStructWithArray__pf3826073315 lv1ins_2_EFC0167049B51FFB215E2284C0988E4B;
		TArray<FMyStructWithArray__pf3826073315> lv1arr_5_6E29525C4699B03778E671BA749C6EA7;
		FMyStruct__pf3826073315 lv0ins_9_A4B4EC294F2B5A8EE604A78342AEC4FD;
	};

	struct FMyStructlv3__pf3826073315
	{
		FMyStructLv2__pf3826073315 lv2ins_3_BC6BEB9D4C9AFC99D6925F881E8DEB21;
		TArray<FMyStructLv2__pf3826073315> lv2arr_6_7A77E9954D2D0A825445FCAE349DE705;
		TArray<FMyStructWithArray__pf3826073315> lv1arr_9_1EE4DD494C52603042686DBB43795940;
		TArray<FVector> vectorarr_13_9869B6EB4C946B8A5B8B32931EDB2413;
	};
};