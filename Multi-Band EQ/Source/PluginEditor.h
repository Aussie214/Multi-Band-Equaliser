/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MultibandEqAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MultibandEqAudioProcessorEditor (MultibandEqAudioProcessor&);
    ~MultibandEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultibandEqAudioProcessor& processor;
    
    //High Pass Vars
    Slider highPassFilterCutoff;
    Slider highPassRes;
    Label highPassFilterLabel;
    Label highPassResLabel;
    
    //Peak Vars 1
    Slider peakFilterCutoff_1;
    Slider peakRes_1;
    Slider peakGain_1;
    Label peakFilterLabel_1;
    Label peakResLabel_1;
    Label peakGainLabel_1;
    
    //Peak Vars 2
    Slider peakFilterCutoff_2;
    Slider peakRes_2;
    Slider peakGain_2;
    Label peakFilterLabel_2;
    Label peakResLabel_2;
    Label peakGainLabel_2;
    
    //Peak Vars 3
    Slider peakFilterCutoff_3;
    Slider peakRes_3;
    Slider peakGain_3;
    Label peakFilterLabel_3;
    Label peakResLabel_3;
    Label peakGainLabel_3;
    
    //Low Pass Vars
    Slider lowPassFilterCutoff;
    Slider lowPassRes;
    Label lowPassFilterLabel;
    Label lowPassResLabel;
    
    //Output Gain Vars
    Slider outputGainSlider;
    Label outputGainLabel;
    
    ImageComponent imageComponent;
    
public:
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> highPassCutoffValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> highPassResValue;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakCutoffValue_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakResValue_1;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakGainValue_1;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakCutoffValue_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakResValue_2;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakGainValue_2;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakCutoffValue_3;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakResValue_3;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> peakGainValue_3;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> lowPassCutoffValue;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> lowPassResValue;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> outputGainValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultibandEqAudioProcessorEditor)
};
