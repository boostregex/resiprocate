#if defined(HAVE_CONFIG_H)
#include "resip/stack/config.hxx"
#endif

#include "resip/stack/Symbols.hxx"

#include "rutil/Data.hxx"

using namespace resip;

const char* Symbols::DefaultSipVersion = "SIP/2.0";
const char* Symbols::DefaultSipScheme = "sip";

const char* Symbols::CRLF = "\r\n";
const char* Symbols::CRLFCRLF = "\r\n\r\n";
const char* Symbols::CR = "\r";
const char* Symbols::LF = "\n";
const char* Symbols::TAB = "\t";

const char* Symbols::AT_SIGN = "@";
const char* Symbols::SPACE = " ";
const char* Symbols::DASH = "-";
const char* Symbols::BAR = "|";
const char* Symbols::DASHDASH = "--";
const char* Symbols::DOT = ".";
const char* Symbols::COLON = ":";
const char* Symbols::EQUALS = "=";
const char* Symbols::SEMI_OR_EQUAL = ";=";
const char* Symbols::COMMA_OR_EQUAL = ",=";
const char* Symbols::SEMI_COLON = ";";
const char* Symbols::SLASH = "/";
const char* Symbols::B_SLASH = "\\";
const char* Symbols::DOUBLE_QUOTE = "\"";
const char* Symbols::LA_QUOTE = "<";
const char* Symbols::RA_QUOTE = ">";
const char* Symbols::COMMA = ",";
const char* Symbols::ZERO = "0";
const char* Symbols::LPAREN = "(";
const char* Symbols::RPAREN = ")";
const char* Symbols::LS_BRACKET = "[";
const char* Symbols::RS_BRACKET = "]";
const char* Symbols::PERIOD = ".";
const char* Symbols::QUESTION = "?";
const char* Symbols::AMPERSAND = "&";
const char* Symbols::PERCENT = "%";
const char* Symbols::STAR ="*";
const char* Symbols::UNDERSCORE ="_";

const char* Symbols::ProtocolName = "SIP";
const char* Symbols::ProtocolVersion = "2.0";
const char* Symbols::UDP = "UDP";
const char* Symbols::TCP = "TCP";
const char* Symbols::TLS = "TLS";
const char* Symbols::DTLS = "DTLS";
const char* Symbols::SCTP = "SCTP";
const char* Symbols::SRVUDP = "_udp.";
const char* Symbols::SRVTCP = "_tcp.";
const char* Symbols::SRVTLS = "_tls.";
const char* Symbols::SRVSCTP = "_sctp.";

const char* Symbols::Sip = "sip";
const char* Symbols::Sips = "sips";
const char* Symbols::Tel = "tel";
const char* Symbols::Pres = "pres";

const char* Symbols::Phone = "phone";
const char* Symbols::Isub = "isub=";
const char* Symbols::Postd = "postd=";

const char* Symbols::auth = "auth";
const char* Symbols::authInt = "auth-int";
const char* Symbols::Digest = "Digest";
const char* Symbols::Basic = "Basic";

const char * const Symbols::MagicCookie = "z9hG4bK";
const char * const Symbols::resipCookie= "-d8754z-";

const int Symbols::DefaultSipPort = 5060;
const int Symbols::SipTlsPort = 5061;
const int Symbols::DefaultSipsPort = 5061;

const char* Symbols::SrvSip = "_sip";
const char* Symbols::SrvSips = "_sips";
const char* Symbols::SrvUdp = "_udp";
const char* Symbols::SrvTcp = "_tcp";
const char* Symbols::NaptrSip = "SIP";
const char* Symbols::NaptrSips = "SIPS";
const char* Symbols::NaptrUdp = "D2U";
const char* Symbols::NaptrTcp = "D2T";

const char* Symbols::audio = "audio";
const char* Symbols::RTP_AVP = "RTP/AVP";
const char* Symbols::RTP_SAVP = "RTP/SAVP"; // used for SRTP
const char* Symbols::UDP_TLS_RTP_SAVP = "UDP/TLS/RTP/SAVP";  // used for DTLS-SRTP

const char* Symbols::Presence = "presence";
const char* Symbols::Required = "required";
const char* Symbols::Optional = "optional";

const char* Symbols::C100rel      = "100rel";
const char* Symbols::Replaces     = "replaces";
const char* Symbols::Timer        = "timer";
const char* Symbols::NoReferSub   = "norefersub";
const char* Symbols::AnswerMode   = "answermode";
const char* Symbols::TargetDialog = "tdialog";
const char* Symbols::Undefined    = "UNDEFINED";

const char* Symbols::Pending = "pending";
const char* Symbols::Active = "active";
const char* Symbols::Terminated = "terminated";

const char* Symbols::Certificate = "certificate";
const char* Symbols::Credential = "credential";

const char* Symbols::SipProfile = "sip-profile";

const char* Symbols::id = "id"; // from RFC 3323

const char* Symbols::Gruu = "gruu";


#if defined(WIN32)
const char *Symbols::pathSep = "\\";
#else
const char *Symbols::pathSep = "/";
#endif

std::bitset<256> makeUTF8_NONASCII()
{
   std::bitset<256> result;
   for(int i=192; i<254; ++i)
   {
      result[i]=true;
   }
   return result;
}

const std::bitset<256> Symbols::UTF8_NONASCII(makeUTF8_NONASCII());

std::bitset<256> makeTEXT_UTF8char()
{
   std::bitset<256> result;
   for(int i=33; i<127; ++i)
   {
      result[i]=true;
   }

   result |= Symbols::UTF8_NONASCII;
   return result;
}

const std::bitset<256> Symbols::TEXT_UTF8char(makeTEXT_UTF8char());

std::bitset<256> makeUTF8_CONT()
{
   std::bitset<256> result;
   for(int i=128; i<192; ++i)
   {
      result[i]=true;
   }
   return result;
}


const std::bitset<256> Symbols::UTF8_CONT(makeUTF8_CONT());

const std::bitset<256> Symbols::LWS(Data::toBitset("\r\n\t "));

const std::bitset<256> Symbols::Reserved(Data::toBitset(";/?:@&=+$,"));
const std::bitset<256> Symbols::Mark(Data::toBitset("-_.!~*'()"));
const std::bitset<256> Symbols::Hex(Data::toBitset("0123456789aAbBcCdDeEfF"));
const std::bitset<256> Symbols::Alpha(Data::toBitset("qwertyuiopasdfghjklzxcvbnm"
                              "QWERTYUIOPASDFGHJKLZXCVBNM"));
const std::bitset<256> Symbols::Digit(Data::toBitset("1234567890"));

std::bitset<256> makeAlphaNum()
{
   std::bitset<256> result(Symbols::Alpha);
   result |= Symbols::Digit;
   return result;
}

const std::bitset<256> Symbols::AlphaNum(makeAlphaNum());

std::bitset<256> makeUnreserved()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Symbols::Mark;
   return result;
}

const std::bitset<256> Symbols::Unreserved(makeUnreserved());

std::bitset<256> makeToken()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Data::toBitset("-.!%*_+`'~");
   return result;
}

const std::bitset<256> Symbols::Token(makeToken());

const std::bitset<256> Symbols::Separators(Data::toBitset("()<>@,;:\\\"/[]?={} \t"));

std::bitset<256> makeWord()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Data::toBitset("-.!%*_+`'~()<>:\\\"/[]?{}");
   return result;
}

const std::bitset<256> Symbols::Word(makeWord());

const std::bitset<256> Symbols::UserUnreserved(Data::toBitset("&=+$,;?/"));

std::bitset<256> makePassword()
{
   std::bitset<256> result(Symbols::Unreserved);
   result |= Data::toBitset("&=+$,");
   return result;
}
const std::bitset<256> Symbols::Password(makePassword());

std::bitset<256> makeBase64()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Data::toBitset("+/=.");
   return result;
}
const std::bitset<256> Symbols::Base64(makeBase64());
const std::bitset<256> Symbols::ParamUnreserved(Data::toBitset("[]/:&+$"));

std::bitset<256> makeParamChar()
{
   std::bitset<256> result(Symbols::ParamUnreserved);
   result |= Symbols::Unreserved;
   return result;
}

const std::bitset<256> Symbols::ParamChar(makeParamChar());

const std::bitset<256> Symbols::HnvUnreserved(Data::toBitset("[]/?:+$"));

std::bitset<256> makeScheme()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Data::toBitset("+-.");
   return result;
}

const std::bitset<256> Symbols::Scheme(makeScheme());

std::bitset<256> makeUriC()
{
   std::bitset<256> result(Symbols::Reserved);
   result |= Symbols::Unreserved;
   return result;
}

const std::bitset<256> Symbols::UriC(makeUriC());


std::bitset<256> makeDomainPartChars()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result['-']=true;
   return result;
}

const std::bitset<256> Symbols::DomainPartChars(makeDomainPartChars());

std::bitset<256> makeUserC()
{
   std::bitset<256> result(Symbols::UserUnreserved);
   result |= Symbols::Unreserved;
   return result;
}

const std::bitset<256> Symbols::UserC(makeUserC());

std::bitset<256> makeReasonC()
{
   std::bitset<256> result(Symbols::Reserved);
   result |= Symbols::Unreserved;
   result |= Symbols::UTF8_NONASCII;
   result |= Symbols::UTF8_CONT;

   result[' ']=true;
   result['\t']=true;
   return result;
}

const std::bitset<256> Symbols::ReasonC(makeReasonC());

std::bitset<256> makeQDText()
{
   std::bitset<256> result;
   result |= Symbols::LWS;

   for(int i=32; i<127; ++i)
   {
      result[i]=true;
   }

   result['\"']=false;
   result['\\']=false;

   result |= Symbols::UTF8_NONASCII;

   return result;
}

const std::bitset<256> Symbols::QDText(makeQDText());

std::bitset<256> makeHfvC()
{
   std::bitset<256> result(Symbols::TEXT_UTF8char);
   result |= Symbols::UTF8_CONT;
   result |= Symbols::LWS;
   return result;
}

const std::bitset<256> Symbols::HfvC(makeHfvC());

std::bitset<256> makePhoneDigit()
{
   std::bitset<256> result(Symbols::Digit);
   result |= Data::toBitset("-.()");
   return result;
}

const std::bitset<256> Symbols::PhoneDigit(makePhoneDigit());

std::bitset<256> makeTelC()
{
   std::bitset<256> result(Symbols::PhoneDigit);
   result |= Data::toBitset("pw*#ABCD");
   return result;
}

const std::bitset<256> Symbols::TelC(makeTelC());

std::bitset<256> makeReg_name()
{
   std::bitset<256> result(Symbols::Unreserved);
   result |= Data::toBitset("$,;:@&=+");
   return result;
}

const std::bitset<256> Symbols::reg_name(makeReg_name());

std::bitset<256> makePCharOrSemiC()
{
   std::bitset<256> result(Symbols::Unreserved);
   result |= Data::toBitset(":@&=+$,;");
   return result;
}

const std::bitset<256> Symbols::PCharOrSemiC(makePCharOrSemiC());

std::bitset<256> makeTelToken()
{
   std::bitset<256> result(Symbols::AlphaNum);
   result |= Data::toBitset("!#$%&'*+-.^_|~");
   return result;
}

const std::bitset<256> Symbols::TelToken(makeTelToken());

/* ====================================================================
 * The Vovida Software License, Version 1.0 
 * 
 * Copyright (c) 2000 Vovida Networks, Inc.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The names "VOCAL", "Vovida Open Communication Application Library",
 *    and "Vovida Open Communication Application Library (VOCAL)" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact vocal@vovida.org.
 *
 * 4. Products derived from this software may not be called "VOCAL", nor
 *    may "VOCAL" appear in their name, without prior written
 *    permission of Vovida Networks, Inc.
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL VOVIDA
 * NETWORKS, INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 * IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by Vovida
 * Networks, Inc. and many individuals on behalf of Vovida Networks,
 * Inc.  For more information on Vovida Networks, Inc., please see
 * <http://www.vovida.org/>.
 *
 */
