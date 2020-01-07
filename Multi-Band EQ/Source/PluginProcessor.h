/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#define HIGH_PASS_FILTER_ID "highPasscutoff"
#define HIGH_PASS_FILTER_NAME "High Pass Frequency"

#define HIGH_PASS_RES_ID "highPassRes"
#define HIGH_PASS_RES_NAME "High Pass Q/Res"

#define HIGH_PASS_BUTTON_ID "highPassButtonID"
#define HIGH_PASS_BUTTON_NAME "highPAssButtonName"

#define PEAK_FILTER_ID_1 "peakfreq_1"
#define PEAK_FILTER_NAME_1 "Peak Frequency Band 1"

#define PEAK_RES_ID_1 "peakRes_1"
#define PEAK_RES_NAME_1 "Peak Q/Res Band 1"

#define PEAK_GAIN_ID_1 "peakgain_1"
#define PEAK_GAIN_NAME_1 "Peak Gain Band 1"

#define PEAK_FILTER_ID_2 "peakfreq_2"
#define PEAK_FILTER_NAME_2 "Peak Frequency Band 2"

#define PEAK_RES_ID_2 "peakRes_2"
#define PEAK_RES_NAME_2 "Peak Q/Res Band 2"

#define PEAK_GAIN_ID_2 "peakgain_2"
#define PEAK_GAIN_NAME_2 "Peak Gain Band 2"

#define PEAK_FILTER_ID_3 "peakfreq_3"
#define PEAK_FILTER_NAME_3 "Peak Frequency Band 3"

#define PEAK_RES_ID_3 "peakRes_3"
#define PEAK_RES_NAME_3 "Peak Q/Res Band 3"

#define PEAK_GAIN_ID_3 "peakgain_3"
#define PEAK_GAIN_NAME_3 "Peak Gain Band 3"

#define LOW_PASS_FILTER_ID "lowPasscutoff"
#define LOW_PASS_FILTER_NAME "Low Pass Frequency"

#define LOW_PASS_RES_ID "lowPassRes"
#define LOW_PASS_RES_NAME "Low Pass Q/Res"

#define OUT_GAIN_ID "outputGainID"
#define OUT_GAIN_NAME "Ouput Gain"

//==============================================================================
/**
*/
class MultibandEqAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MultibandEqAudioProcessor();
    ~MultibandEqAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //User defined methods
    void updateFilter();
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    //User defined vars
    AudioProcessorValueTreeState tree;
    double lastSampleRate;
    AudioParameterFloat* gain_coeff;


private:
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float> , dsp::IIR::Coefficients<float>> highPassFilter;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float> , dsp::IIR::Coefficients<float>> peakFilter_1;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float> , dsp::IIR::Coefficients<float>> peakFilter_2;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float> ,dsp::IIR::Coefficients<float>> peakFilter_3;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float> , dsp::IIR::Coefficients<float>> lowPassFilter;
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultibandEqAudioProcessor)
};
