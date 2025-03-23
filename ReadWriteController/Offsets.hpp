#pragma once

#include <Windows.h>

namespace Offsets
{
	// Entities
	const DWORD entityListPtr					{ 0x18AC04 };			//Ptr to array of entities[0]
	const DWORD localPlayerPtr4					{ 0x18AC00 };

	//entity structure
	//vTablePtr 0x0
	const DWORD camVector						{ 0x04 };				//vec3
	const DWORD speedVector						{ 0x10 };				//vec3
	const DWORD unknownVector					{ 0x1C };				//vec3
	const DWORD feetVector						{ 0x28 };				//vec3
	const DWORD viewAngles						{ 0x34 };				//vec3
	const DWORD gravity							{ 0x48 };				//float
	const DWORD isOnGround						{ 0x5D };				//uint8
	const DWORD isJumping						{ 0x5F };				//uint8
	const DWORD isMoving						{ 0x64 };				//uint8
	const DWORD moveDirection					{ 0x74 };				//uint32
	const DWORD moveDirection2					{ 0x80 };				//uint32
	const DWORD healthOffset					{ 0xEC };				//uint32
	const DWORD armorOffset						{ 0xF0 };				//uint32
	const DWORD nadeAmount						{ 0x144 };				//uint32
	const DWORD playerName						{ 0x205 };				//text8
	const DWORD teamFlag						{ 0x30C };				//uint32
	const DWORD weaponPtr						{ 0x374 };				//uint32 currentAmmo = moduleBaseAddress+0x18AC00+374+14+0;
	const DWORD currentAmmo						{ 0x374 + 0x14 + 0 };
}

namespace Entity
{
	struct vector3D //to handle vectors
	{
		float x{};
		float y{};
		float z{};
	};

	struct eulerAngles //to handle yaw and pitch (roll is 0 in asssaultcube)
	{
		float Yaw{};
		float Pitch{};
	};
}