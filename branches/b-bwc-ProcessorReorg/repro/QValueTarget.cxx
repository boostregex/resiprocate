#include "repro/QValueTarget.hxx"


namespace repro
{


QValueTarget::QValueTarget()
{
   mPriorityMetric=0;
   mShouldAutoProcess=true;
   mStatus=Target::Candidate;
}

QValueTarget::QValueTarget(const resip::Uri& uri):
   Target(uri)
{
   if(uri.exists(resip::p_q))
   {
      mPriorityMetric=uri.param(resip::p_q);
      mShouldAutoProcess=true;
   }
   
}

QValueTarget::QValueTarget(const resip::NameAddr& nameAddr):
   Target(nameAddr)
{
   if(nameAddr.uri().exists(resip::p_q))
   {
      mPriorityMetric=nameAddr.uri().param(resip::p_q);
      mShouldAutoProcess=true;
   }
   
}

QValueTarget::QValueTarget(const Target& orig):
   Target(orig)
{
   if(mNameAddr.uri().exists(resip::p_q))
   {
      mPriorityMetric=mNameAddr.uri().param(resip::p_q);
      mShouldAutoProcess=true;      
   }
}

QValueTarget::QValueTarget(const QValueTarget& orig)
{
   mPriorityMetric=orig.mPriorityMetric;
   mShouldAutoProcess=orig.mShouldAutoProcess;
   mNameAddr=orig.mNameAddr;
   mVia=orig.mVia;
   mStatus=orig.mStatus;
}
   
QValueTarget::~QValueTarget(){}

const resip::Uri& 
QValueTarget::setUri(const resip::Uri& uri)
{
   if(uri.exists(resip::p_q))
   {
      mPriorityMetric=uri.param(resip::p_q);
   }
   else
   {
      mPriorityMetric=1;
   }

   return mNameAddr.uri()=uri;
}

const resip::NameAddr& 
QValueTarget::setNameAddr(const resip::NameAddr& nameAddr)
{
   if(mNameAddr.uri().exists(resip::p_q))
   {
      mPriorityMetric=nameAddr.uri().param(resip::p_q);
   }
   else
   {
      mPriorityMetric=1;
   }

   return mNameAddr=nameAddr;
}

QValueTarget* 
QValueTarget::clone() const
{
   return new QValueTarget(*this);
}

}

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
 */
