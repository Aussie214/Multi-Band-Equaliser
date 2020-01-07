/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultibandEqAudioProcessorEditor::MultibandEqAudioProcessorEditor (MultibandEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //High Pass Val Init From Processor
    highPassCutoffValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.tree, HIGH_PASS_FILTER_ID, highPassFilterCutoff);
    highPassResValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, HIGH_PASS_RES_ID, highPassRes);
    
    //Peak Val Init From Processor 1
    peakCutoffValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.tree, PEAK_FILTER_ID_1, peakFilterCutoff_1);
    peakResValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_RES_ID_1, peakRes_1);
    peakGainValue_1 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_GAIN_ID_1, peakGain_1);
    
    //Peak Val Init From Processor 2
    peakCutoffValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.tree, PEAK_FILTER_ID_2, peakFilterCutoff_2);
    peakResValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_RES_ID_2, peakRes_2);
    peakGainValue_2 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_GAIN_ID_2, peakGain_2);
    
    //Peak Val Init From Processor 3
    peakCutoffValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.tree, PEAK_FILTER_ID_3, peakFilterCutoff_3);
    peakResValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_RES_ID_3, peakRes_3);
    peakGainValue_3 = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, PEAK_GAIN_ID_3, peakGain_3);
    
    //Low Pass Val Init From Processor
    lowPassCutoffValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment> (processor.tree, LOW_PASS_FILTER_ID, lowPassFilterCutoff);
    lowPassResValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, LOW_PASS_RES_ID, lowPassRes);
    
    //Output Gain Init From Processor
    outputGainValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.tree, OUT_GAIN_ID, outputGainSlider);
    
    
    setSize (800, 500);
    
    //High Pass Freq Slider
highPassFilterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    highPassFilterCutoff.setTextBoxStyle(Slider::TextBoxBelow, false, 125, 25);
    highPassFilterCutoff.setRange(20.0f, 20000.0f);
highPassFilterCutoff.setValue(*processor.tree.getRawParameterValue(HIGH_PASS_FILTER_ID));
    //highPassFilterLabel.setText("Low Cut Frequency", dontSendNotification);
    //highPassFilterLabel.attachToComponent(&highPassFilterCutoff, false);
    addAndMakeVisible(highPassFilterCutoff);
    //addAndMakeVisible(highPassFilterLabel);
    
    //High Pass Res Slider
    highPassRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    highPassRes.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    highPassRes.setRange(0.1f, 5.0f);
    highPassRes.setValue(*processor.tree.getRawParameterValue(HIGH_PASS_RES_ID));
    //highPassResLabel.setText("Low Cut Slope/Q", dontSendNotification);
    //highPassResLabel.attachToComponent(&highPassRes, false);
    addAndMakeVisible(highPassRes);
    //addAndMakeVisible(highPassResLabel);
    
    //Peak Freq Slider 1
    peakFilterCutoff_1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakFilterCutoff_1.setTextBoxStyle(Slider::TextBoxBelow, false, 125, 25);
    peakFilterCutoff_1.setRange(20.0f, 20000.0f);
    peakFilterCutoff_1.setValue(*processor.tree.getRawParameterValue(PEAK_FILTER_ID_1));
    //peakFilterLabel_1.setText("Frequency Band 1", dontSendNotification);
    //peakFilterLabel_1.attachToComponent(&peakFilterCutoff_1, false);
    addAndMakeVisible(peakFilterCutoff_1);
    //addAndMakeVisible(peakFilterLabel_1);
        
    //Peak Res Slider 1
    peakRes_1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakRes_1.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakRes_1.setRange(0.1f, 75.0f);
    peakRes_1.setValue(*processor.tree.getRawParameterValue(PEAK_RES_ID_1));
    //peakResLabel_1.setText("Slope/Q Band 1", dontSendNotification);
    //peakResLabel_1.attachToComponent(&peakRes_1, false);
    addAndMakeVisible(peakRes_1);
    //addAndMakeVisible(peakResLabel_1);
    
    //Peak Gain Slider 1
    peakGain_1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakGain_1.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakGain_1.setRange(0.2f, 2.5f);
    peakGain_1.setValue(*processor.tree.getRawParameterValue(PEAK_GAIN_ID_1));
    //peakGainLabel_1.setText("Gain Band 1", dontSendNotification);
    //peakGainLabel_1.attachToComponent(&peakGain_1, false);
    addAndMakeVisible(peakGain_1);
    //addAndMakeVisible(peakGainLabel_1);
    
    //Peak Freq Slider 2
    peakFilterCutoff_2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakFilterCutoff_2.setTextBoxStyle(Slider::TextBoxBelow, false, 125, 25);
    peakFilterCutoff_2.setRange(20.0f, 20000.0f);
    peakFilterCutoff_2.setValue(*processor.tree.getRawParameterValue(PEAK_FILTER_ID_2));
    //peakFilterLabel_2.setText("Frequency Band 2", dontSendNotification);
    //peakFilterLabel_2.attachToComponent(&peakFilterCutoff_2, false);
    addAndMakeVisible(peakFilterCutoff_2);
    //addAndMakeVisible(peakFilterLabel_2);
        
    //Peak Res Slider 2
    peakRes_2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakRes_2.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakRes_2.setRange(0.1f, 75.0f);
    peakRes_2.setValue(*processor.tree.getRawParameterValue(PEAK_RES_ID_2));
    //peakResLabel_2.setText("Slope/Q Band 2", dontSendNotification);
    //peakResLabel_2.attachToComponent(&peakRes_2, false);
    addAndMakeVisible(peakRes_2);
    //addAndMakeVisible(peakResLabel_2);
    
    //Peak Gain Slider 2
    peakGain_2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakGain_2.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakGain_2.setRange(0.2f, 2.5f);
    peakGain_2.setValue(*processor.tree.getRawParameterValue(PEAK_GAIN_ID_2));
    //peakGainLabel_2.setText("Gain Band 2", dontSendNotification);
    //peakGainLabel_2.attachToComponent(&peakGain_2, false);
    addAndMakeVisible(peakGain_2);
    //addAndMakeVisible(peakGainLabel_2);
    
    //Peak Freq Slider 3
    peakFilterCutoff_3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakFilterCutoff_3.setTextBoxStyle(Slider::TextBoxBelow, false, 125, 25);
    peakFilterCutoff_3.setRange(20.0f, 20000.0f);
    peakFilterCutoff_3.setValue(*processor.tree.getRawParameterValue(PEAK_FILTER_ID_3));
    //peakFilterLabel_3.setText("Frequency Band 3", dontSendNotification);
    //peakFilterLabel_3.attachToComponent(&peakFilterCutoff_3, false);
    addAndMakeVisible(peakFilterCutoff_3);
    //addAndMakeVisible(peakFilterLabel_3);
        
    //Peak Res Slider 3
    peakRes_3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakRes_3.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakRes_3.setRange(0.1f, 75.0f);
    peakRes_3.setValue(*processor.tree.getRawParameterValue(PEAK_RES_ID_3));
    //peakResLabel_3.setText("Slope/Q Band 3", dontSendNotification);
    //peakResLabel_3.attachToComponent(&peakRes_3, false);
    addAndMakeVisible(peakRes_3);
    //addAndMakeVisible(peakResLabel_3);
    
    //Peak Gain Slider 3
    peakGain_3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    peakGain_3.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    peakGain_3.setRange(0.2f, 2.5f);
    peakGain_3.setValue(*processor.tree.getRawParameterValue(PEAK_GAIN_ID_3));
    //peakGainLabel_3.setText("Gain Band 3", dontSendNotification);
    //peakGainLabel_3.attachToComponent(&peakGain_3, false);
    addAndMakeVisible(peakGain_3);
    //addAndMakeVisible(peakGainLabel_3);
    
    //Low Pass Freq Slider
    lowPassFilterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    lowPassFilterCutoff.setTextBoxStyle(Slider::TextBoxBelow, false, 125, 25);
    lowPassFilterCutoff.setRange(20.0f, 20000.0f);
lowPassFilterCutoff.setValue(*processor.tree.getRawParameterValue(LOW_PASS_FILTER_ID));
    //lowPassFilterLabel.setText("High Cut Frequency", dontSendNotification);
    //lowPassFilterLabel.attachToComponent(&lowPassFilterCutoff, false);
    addAndMakeVisible(lowPassFilterCutoff);
    //addAndMakeVisible(lowPassFilterLabel);
    
    //Low Pass Res Slider
    lowPassRes.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    lowPassRes.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 25);
    lowPassRes.setRange(0.1f, 5.0f);
    lowPassRes.setValue(*processor.tree.getRawParameterValue(LOW_PASS_RES_ID));
    //lowPassResLabel.setText("High Cut Slope/Q", dontSendNotification);
    //lowPassResLabel.attachToComponent(&lowPassRes, false);
    addAndMakeVisible(lowPassRes);
    //addAndMakeVisible(lowPassResLabel);
    
    //Output Gain Slider
    outputGainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    //outputGainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    outputGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 40, 25);
    outputGainSlider.setRange(0.01f, 2.0f);
    auto temp = *processor.tree.getRawParameterValue(OUT_GAIN_ID);
    outputGainSlider.setValue(temp);
    //outputGainLabel.setText("Gain", dontSendNotification);
    //outputGainLabel.attachToComponent(&outputGainSlider, false);
    addAndMakeVisible(outputGainSlider);
    //addAndMakeVisible(outputGainLabel);
    
    
    //Slider Editing
    getLookAndFeel().setColour (Slider::thumbColourId, Colours::red);
    
    peakFilterCutoff_1.setColour(Slider::thumbColourId, Colours::orange);
    peakRes_1.setColour(Slider::thumbColourId, Colours::orange);
    peakGain_1.setColour(Slider::thumbColourId, Colours::orange);
    
    peakFilterCutoff_2.setColour(Slider::thumbColourId, Colours::yellow);
    peakRes_2.setColour(Slider::thumbColourId, Colours::yellow);
    peakGain_2.setColour(Slider::thumbColourId, Colours::yellow);
    
    peakFilterCutoff_3.setColour(Slider::thumbColourId, Colours::green);
    peakRes_3.setColour(Slider::thumbColourId, Colours::green);
    peakGain_3.setColour(Slider::thumbColourId, Colours::green);
    
    lowPassFilterCutoff.setColour(Slider::thumbColourId, Colours::indigo);
    lowPassRes.setColour(Slider::thumbColourId, Colours::indigo);
    
    outputGainSlider.setColour(Slider::thumbColourId, Colours::violet);
    
    //getLookAndFeel().setColour(Label::textColourId, Colours::black);
    //LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName ("Comic Sans");
}

MultibandEqAudioProcessorEditor::~MultibandEqAudioProcessorEditor()
{
}

//==============================================================================
void MultibandEqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll(Colours::turquoise);
    //First 2 deal with opacity, last 6 deal with color choice
    //g.fillAll(Colour::fromString("0xfc2266a2"));
    
    File fileImg = File("/Users/aussie/JUCE/EQ_Background.png");
    Image img = ImageFileFormat::loadFrom(fileImg);
    imageComponent.setImage(img);
    addAndMakeVisible(&imageComponent);
    g.drawImageAt(img, 0, 0);
    
    //g.fillAll(Colour::fromString("0xfc2266a2"));
    //g.drawImageAt(img, 0, 0);
    
    g.setColour (Colours::black);
    g.setFont (15.0f);
    
}

void MultibandEqAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //imageComponent.setBounds(0, 0, 500, 500);
    
    //(800, 500)
    
    //High Pass Slider Layout
    highPassFilterCutoff.setBounds(20, 45, 125, 125);
    highPassRes.setBounds(20, 210, 125, 125);
    
    //Peak Slider Layout 1
    peakFilterCutoff_1.setBounds(175, 50, 110, 110);
    peakRes_1.setBounds(175, 210, 110, 110);
    peakGain_1.setBounds(175, 360, 110, 110);
    
    //Peak Slider Layout 2
    peakFilterCutoff_2.setBounds(325, 50, 110, 110);
    peakRes_2.setBounds(325, 210, 110, 110);
    peakGain_2.setBounds(325, 360, 110, 110);
    
    //Peak Slider Layout 3
    peakFilterCutoff_3.setBounds(475, 50, 110, 110);
    peakRes_3.setBounds(475, 210, 110, 110);
    peakGain_3.setBounds(475, 360, 110, 110);
    
    //Low Pass Slider Layout
    lowPassFilterCutoff.setBounds(632, 45, 125, 125);
    lowPassRes.setBounds(632, 210, 125, 125);
    
    //Output Gain Slider Layout
    outputGainSlider.setBounds(760, 50, 40, 400);
    
}
