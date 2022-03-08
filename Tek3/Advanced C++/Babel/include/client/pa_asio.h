#ifndef PA_ASIO_H
#define PA_ASIO_H


#include "portaudio.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


PaError PaAsio_GetAvailableBufferSizes( PaDeviceIndex device,
                long *minBufferSizeFrames, long *maxBufferSizeFrames, long *preferredBufferSizeFrames, long *granularity );


#define PaAsio_GetAvailableLatencyValues PaAsio_GetAvailableBufferSizes


PaError PaAsio_ShowControlPanel( PaDeviceIndex device, void* systemSpecific );




PaError PaAsio_GetInputChannelName( PaDeviceIndex device, int channelIndex,
        const char** channelName );

          
  PaError PaAsio_GetOutputChannelName( PaDeviceIndex device, int channelIndex,
          const char** channelName );
  
  
  PaError PaAsio_SetStreamSampleRate( PaStream* stream, double sampleRate );
  
  
  #define paAsioUseChannelSelectors      (0x01)
  
  typedef struct PaAsioStreamInfo{
      unsigned long size;             
      PaHostApiTypeId hostApiType;    
      unsigned long version;          
      unsigned long flags;
  
      /* Support for opening only specific channels of an ASIO device.
          If the paAsioUseChannelSelectors flag is set, channelSelectors is a
          pointer to an array of integers specifying the device channels to use.
          When used, the length of the channelSelectors array must match the
          corresponding channelCount parameter to Pa_OpenStream() otherwise a
          crash may result.
          The values in the selectors array must specify channels within the
          range of supported channels for the device or paInvalidChannelCount will
          result.
      */
      int *channelSelectors;
  }PaAsioStreamInfo;
  
  
  #ifdef __cplusplus
  }
  #endif /* __cplusplus */
  
  #endif /* PA_ASIO_H */