//*****************************************************************************
/// Synchrotron SOLEIL
///
/// EigerAPI C++
/// File     : EigerDefines.h
/// Creation : 2014/09/03
/// Author   : William BOULADOUX
///
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the GNU General Public License as published by the Free Software
/// Foundation; version 2 of the License.
/// 
/// This program is distributed in the hope that it will be useful, but WITHOUT 
/// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
/// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
///
//*****************************************************************************
//
/*!  \brief     Defines for EigerAPI
*/
//*****************************************************************************

#ifndef _EIGERDEFINES_H
#define _EIGERDEFINES_H

#include <iostream>
#include <sstream>
#include <exception>
#include <memory>

namespace eigerapi
{

//#define C_EIGERAPI_EIGER1M_WIDTH  1030
//#define C_EIGERAPI_EIGER1M_HEIGHT 1065
#define C_NAME_PATTERN "lima"

const char RESOURCE_NOT_FOUND[]    = "Resource not found: ";
const char JSON_PARSE_FAILED[]     = "Json parse failed: ";
const char DATA_TYPE_NOT_HANDLED[] = "Data type not handled: ";
const char EMPTY_RESPONSE[]        = "Empty response";
const char READONLY_RESOURCE[]     = "Resource is read only: ";
const char CREATE_FILE[]           = "Unable to create file: ";
const char BAD_REQUEST[]           = "Command failed (HTTP 400): ";

// Trigger modes
typedef enum
{
   ETRIGMODE_UNKNOWN = -1,
   ETRIGMODE_EXPO = 0,
   ETRIGMODE_EXTT,
   ETRIGMODE_EXTM,
   ETRIGMODE_EXTE
} ENUM_TRIGGERMODE;


// Server subsystems
typedef enum
{
   ESUBSYSTEM_DETECTOR,
   ESUBSYSTEM_FILEWRITER
} ENUM_SUBSYSTEM;

// Subsystem states
typedef enum
{
   ESTATE_UNKNOWN = -1,  
   ESTATE_NA = 0, 
   ESTATE_DISABLED,
   ESTATE_READY,
   ESTATE_IDLE, 
   ESTATE_ACQUIRE,
   ESTATE_ERROR,
   ESTATE_INITIALIZE,
   ESTATE_CONFIGURE,
   ESTATE_TEST
} ENUM_STATE;


//=============================================================================
// Class EigerSize (holds 2D dimensions)
//=============================================================================
class EigerSize
{
public:
    EigerSize() 
    {
        m_x = 0;
        m_y = 0;
    }
    
    EigerSize(const int x, const int y)
    {
        m_x = x;
        m_y = y;
    }

    int getX() { return m_x; }
    int getY() { return m_y; }

  private:
      int m_x;
      int m_y;
};


//=============================================================================
/// Eiger exceptions
///
/// This class is designed to hold Eiger exceptions
//=============================================================================
class EigerException: public std::exception
{
public:
  EigerException(const char *pcszDesc, const char* pcszArg, const char *pcszOrigin,
		 const char *filename = NULL)
  {
    std::ostringstream oss;
    oss << std::endl
        << "--------------------------------------------------------------------------------------------" << std::endl
        << "EigerException " << std::endl 
        << "Description: "   << pcszDesc << ":" << pcszArg << std::endl 
        << "Origin     : "   << pcszOrigin << std::endl;
      if(filename)
        oss << "Location   : "   << filename << std::endl;

      oss << "--------------------------------------------------------------------------------------------" << std::endl;

    msg = oss.str();
  }

  virtual ~EigerException() throw() 
  { 
  }

  virtual const char * what() const throw() 
  { 
      return msg.c_str(); 
  }   
  
  /// Prints error message on console
  void dump(void) const throw() 
  {
    std::cerr << what() << "\n"; 
  }

private: 
  std::string msg;  

};

} // namespace eigerapi


#define EIGER_EXPEND_LINE__SUB(x) #x
#define EIGER_EXPEND_LINE_(x) EIGER_EXPEND_LINE__SUB(x)
#define EIGER_LOCATION __FILE__ " line " EIGER_EXPEND_LINE_(__LINE__)

#define THROW_EIGER_EXCEPTION(pcszDesc,pcszArg) \
  throw eigerapi::EigerException(pcszDesc,pcszArg,__PRETTY_FUNCTION__,EIGER_LOCATION)

#endif
