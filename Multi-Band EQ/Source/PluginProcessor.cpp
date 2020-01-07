/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultibandEqAudioProcessor::MultibandEqAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), tree(*this, nullptr, "PARAMETER", createParameterLayout()), highPassFilter(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20.0f, 1.0f)),
                        peakFilter_1(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 250.0f, 1.0f, 1.0f)),
                        peakFilter_2(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 1000.0f, 1.0f, 1.0f)),
                        peakFilter_3(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 3500.0f, 1.0f, 1.0f)),
                        lowPassFilter(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000.0f, 1.0f)),
                        gain_coeff( new AudioParameterFloat(OUT_GAIN_ID, OUT_GAIN_NAME, 0.01f, 2.0f, 0.425f))
#endif
{
}

AudioProcessorValueTreeState::ParameterLayout MultibandEqAudioProcessor::createParameterLayout() {
    
    std::vector<std::unique_ptr<RangedAudioParameter>> params;
    
    //High Pass params
    auto highPassFilterParam = std::make_unique<AudioParameterFloat>(HIGH_PASS_FILTER_ID, HIGH_PASS_FILTER_NAME, 20.0f, 20000.0f, 20.0f);
    auto highPassResParam = std::make_unique<AudioParameterFloat>(HIGH_PASS_RES_ID, HIGH_PASS_RES_NAME, 0.1f, 5.0f, 1.0f);
    
    //Peak params 1
    auto peakFilterParam_1 = std::make_unique<AudioParameterFloat>(PEAK_FILTER_ID_1, PEAK_FILTER_NAME_1, 20.0f, 20000.0f, 250.0f);
    auto peakResParam_1 = std::make_unique<AudioParameterFloat>(PEAK_RES_ID_1, PEAK_RES_NAME_1, 0.1f, 75.0f, 1.0f);
    auto peakGainParam_1 = std::make_unique<AudioParameterFloat>(PEAK_GAIN_ID_1, PEAK_GAIN_NAME_1, 0.2f, 2.5f, 1.0f);
    
    //Peak params 2
    auto peakFilterParam_2 = std::make_unique<AudioParameterFloat>(PEAK_FILTER_ID_2, PEAK_FILTER_NAME_2, 20.0f, 20000.0f, 1000.0f);
    auto peakResParam_2 = std::make_unique<AudioParameterFloat>(PEAK_RES_ID_2, PEAK_RES_NAME_2, 0.1f, 75.0f, 1.0f);
    auto peakGainParam_2 = std::make_unique<AudioParameterFloat>(PEAK_GAIN_ID_2, PEAK_GAIN_NAME_2, 0.2f, 2.5f, 1.0f);
    
    //Peak params 3
    auto peakFilterParam_3 = std::make_unique<AudioParameterFloat>(PEAK_FILTER_ID_3, PEAK_FILTER_NAME_3, 20.0f, 20000.0f, 3500.0f);
    auto peakResParam_3 = std::make_unique<AudioParameterFloat>(PEAK_RES_ID_3, PEAK_RES_NAME_3, 0.1f, 75.0f, 1.0f);
    auto peakGainParam_3 = std::make_unique<AudioParameterFloat>(PEAK_GAIN_ID_3, PEAK_GAIN_NAME_3, 0.2f, 2.5f, 1.0f);
    
    //Low Pass params
    auto lowPassFilterParam = std::make_unique<AudioParameterFloat>(LOW_PASS_FILTER_ID, LOW_PASS_FILTER_NAME, 20.0f, 20000.0f, 20000.0f);
    auto lowPassResParam = std::make_unique<AudioParameterFloat>(LOW_PASS_RES_ID, LOW_PASS_RES_NAME, 0.1f, 5.0f, 1.0f);
    
    //Output Gain params
    auto outputGainParam = std::make_unique<AudioParameterFloat>(OUT_GAIN_ID, OUT_GAIN_NAME, 0.01f, 2.0f, 0.425f);
    
    params.push_back(std::move(highPassFilterParam));
    params.push_back(std::move(highPassResParam));
    
    params.push_back(std::move(peakFilterParam_1));
    params.push_back(std::move(peakResParam_1));
    params.push_back(std::move(peakGainParam_1));
    
    params.push_back(std::move(peakFilterParam_2));
    params.push_back(std::move(peakResParam_2));
    params.push_back(std::move(peakGainParam_2));
    
    params.push_back(std::move(peakFilterParam_3));
    params.push_back(std::move(peakResParam_3));
    params.push_back(std::move(peakGainParam_3));
    
    params.push_back(std::move(lowPassFilterParam));
    params.push_back(std::move(lowPassResParam));
    
    params.push_back(std::move(outputGainParam));
    
    return{params.begin(), params.end()};
}

MultibandEqAudioProcessor::~MultibandEqAudioProcessor()
{
}

//==============================================================================
const String MultibandEqAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MultibandEqAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MultibandEqAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MultibandEqAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MultibandEqAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MultibandEqAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MultibandEqAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MultibandEqAudioProcessor::setCurrentProgram (int index)
{
}

const String MultibandEqAudioProcessor::getProgramName (int index)
{
    return {};
}

void MultibandEqAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MultibandEqAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    lastSampleRate = sampleRate;
    
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    //gain_coeff->setValueNotifyingHost( Decibels::gainToDecibels(gain_coeff->get()) );
    
    highPassFilter.prepare(spec);
    peakFilter_1.prepare(spec);
    peakFilter_2.prepare(spec);
    peakFilter_3.prepare(spec);
    lowPassFilter.prepare(spec);
    
    highPassFilter.reset();
    peakFilter_1.reset();
    peakFilter_2.reset();
    peakFilter_3.reset();
    lowPassFilter.reset();
}

void MultibandEqAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MultibandEqAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MultibandEqAudioProcessor::updateFilter() {
    
    float highPassFreq = *tree.getRawParameterValue(HIGH_PASS_FILTER_ID);
    float highPassRes = *tree.getRawParameterValue(HIGH_PASS_RES_ID);
    
    *highPassFilter.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, highPassFreq, highPassRes);
    
    float peakFreq_1 = *tree.getRawParameterValue(PEAK_FILTER_ID_1);
    float peakRes_1 = *tree.getRawParameterValue(PEAK_RES_ID_1);
    float peakGain_1 = *tree.getRawParameterValue(PEAK_GAIN_ID_1);
    
    *peakFilter_1.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, peakFreq_1, peakRes_1, peakGain_1);
    
    float peakFreq_2 = *tree.getRawParameterValue(PEAK_FILTER_ID_2);
    float peakRes_2 = *tree.getRawParameterValue(PEAK_RES_ID_2);
    float peakGain_2 = *tree.getRawParameterValue(PEAK_GAIN_ID_2);
    
    *peakFilter_2.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, peakFreq_2, peakRes_2, peakGain_2);
    
    float peakFreq_3 = *tree.getRawParameterValue(PEAK_FILTER_ID_3);
    float peakRes_3 = *tree.getRawParameterValue(PEAK_RES_ID_3);
    float peakGain_3 = *tree.getRawParameterValue(PEAK_GAIN_ID_3);
    
    *peakFilter_3.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, peakFreq_3, peakRes_3, peakGain_3);
    
    float lowPassFreq = *tree.getRawParameterValue(LOW_PASS_FILTER_ID);
    float lowPassRes = *tree.getRawParameterValue(LOW_PASS_RES_ID);
    
    *lowPassFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, lowPassFreq, lowPassRes);
    
    float outGain = *tree.getRawParameterValue(OUT_GAIN_ID);
    gain_coeff->setValueNotifyingHost( outGain );
    
    
}

void MultibandEqAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    dsp::AudioBlock<float> block (buffer);
    updateFilter();

    highPassFilter.process(dsp::ProcessContextReplacing<float> (block));
    peakFilter_1.process(dsp::ProcessContextReplacing<float> (block));
    peakFilter_2.process(dsp::ProcessContextReplacing<float> (block));
    peakFilter_3.process(dsp::ProcessContextReplacing<float> (block));
    lowPassFilter.process(dsp::ProcessContextReplacing<float> (block));
    
    //Decibels::gainToDecibels(gain_coeff->get());
    
    //Apply Gain
    //gain_coeff->setValueNotifyingHost( pow(10, (gain_coeff->get()) / 20) );
    for (int channelNum = 0; channelNum < buffer.getNumChannels(); ++channelNum) {
        float* channel_data = buffer.getWritePointer(channelNum);
        for (int sampleNum = 0; sampleNum < buffer.getNumSamples(); ++sampleNum) {
            channel_data[sampleNum] = buffer.getSample(channelNum, sampleNum);
            channel_data[sampleNum] = channel_data[sampleNum] * gain_coeff->get();
        }
    }
}

//==============================================================================
bool MultibandEqAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MultibandEqAudioProcessor::createEditor()
{
    return new MultibandEqAudioProcessorEditor (*this);
}

//==============================================================================
void MultibandEqAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    auto state = tree.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void MultibandEqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    
       if (xmlState.get() != nullptr)
           if (xmlState->hasTagName (tree.state.getType()))
               tree.replaceState (ValueTree::fromXml (*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MultibandEqAudioProcessor();
}
