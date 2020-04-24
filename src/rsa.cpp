/*
  The Forgotten Client
  Copyright (C) 2020 Saiyans King

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "rsa.h"

RSA::RSA()
{
	m_e = 65537;
	m_mod.fromString(CLIENT_RSA_KEY, 10);
}

RSA::~RSA()
{
}

void RSA::setKey(const char* publicKey)
{
	m_mod.fromString(publicKey, 10);
}

void RSA::encrypt(Uint8* msg) const
{
	Uint1024 plain;
	plain.importData(msg);

	Uint1024 encrypted = base_uint_powm<1024>(plain, m_e, m_mod);
	encrypted.exportData(msg);
}
