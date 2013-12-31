#ifndef __LOLIROFLE_IRCBOT_IRCBOT_H_INCLUDED__
#define __LOLIROFLE_IRCBOT_IRCBOT_H_INCLUDED__

#include <lolie/TypeAliases.h>
#include <lolie/Stringp.h>
#include "ircinterface/irc.h"
#include "IRCBot_Error.h"

#define IRCBOT_SIGNATURE "Flygande Toalett Toabot v1.0.5-20131229"

struct IRCBot{
	struct irc_connection connection;
	Stringp hostname;
	Stringp nickname;
	Stringp username;
	Stringp realname;
	bool connected;
	struct IRCBot_Error error;

	Stringp commandPrefix;
};

bool IRCBot_initialize(struct IRCBot* bot);
bool IRCBot_free(struct IRCBot* bot);

bool IRCBot_connect(struct IRCBot* bot,Stringcp host,unsigned short port);
bool IRCBot_disconnect(struct IRCBot* bot);

#define IRCBot_isConnected(bot) ((bot)->connected)

//IRCBot must be connected for these functions
void IRCBot_setNickname(struct IRCBot* bot,Stringcp name);
void IRCBot_setUsername(struct IRCBot* bot,Stringcp name);
void IRCBot_setRealname(struct IRCBot* bot,Stringcp name);

void IRCBot_setCommandPrefix(struct IRCBot* bot,Stringcp prefix);
void IRCBot_setCommandPrefixc(struct IRCBot* bot,char prefix);

#define IRCBOT_ERROR_CONNECT 1
#define IRCBOT_ERROR_MEMORY  2

#endif
