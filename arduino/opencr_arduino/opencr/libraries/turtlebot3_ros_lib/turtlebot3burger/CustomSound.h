#ifndef _ROS_turtlebot3burger_CustomSound_h
#define _ROS_turtlebot3burger_CustomSound_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace turtlebot3burger
{

  class CustomSound : public ros::Msg
  {
    public:
      typedef uint16_t _frequency_type;
      _frequency_type frequency;
      typedef uint16_t _duration_type;
      _duration_type duration;

    CustomSound():
      frequency(0),
      duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->frequency >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequency >> (8 * 1)) & 0xFF;
      offset += sizeof(this->frequency);
      *(outbuffer + offset + 0) = (this->duration >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration >> (8 * 1)) & 0xFF;
      offset += sizeof(this->duration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->frequency =  ((uint16_t) (*(inbuffer + offset)));
      this->frequency |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->frequency);
      this->duration =  ((uint16_t) (*(inbuffer + offset)));
      this->duration |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->duration);
     return offset;
    }

    const char * getType(){ return "turtlebot3burger/CustomSound"; };
    const char * getMD5(){ return "e70bc64fae44b348de12b254f19a186d"; };

  };

}
#endif