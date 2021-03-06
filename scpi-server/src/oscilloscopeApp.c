/**
 * $Id: $
 *
 * @brief Red Pitaya Scpi server generate SCPI commands implementation
 *
 * @Author Red Pitaya
 *
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */

#include <syslog.h>
#include "oscilloscopeApp.h"
#include <string.h>

#include "../../api/rpApplications/src/rpApp.h"
#include "../3rdparty/libs/scpi-parser/libscpi/inc/scpi/parser.h"
#include "utils.h"

scpi_result_t RP_APP_OscRun(scpi_t *context) {
    int result = rpApp_OscRun();
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:RUN Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:RUN Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscStop(scpi_t *context) {
    int result = rpApp_OscStop();
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:STOP Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:STOP Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscReset(scpi_t *context) {
    int result = rpApp_OscReset();
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:RST Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:RST Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscAutoscale(scpi_t *context) {
    int result = rpApp_OscAutoScale();
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:AUTOSCALE Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:AUTOSCALE Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSingle(scpi_t *context) {
    int result = rpApp_OscSingle();
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:SINGLE Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:SINGLE Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscRunning(scpi_t *context) {
    bool running;
    int result = rpApp_OscIsRunning(&running);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:RUNNING Failed: %s.", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultBool(context, running);
    syslog(LOG_INFO, "*OSC:RUNNING Successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscChannel1SetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscSetAmplitudeOffset(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2SetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscSetAmplitudeOffset(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3SetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscSetAmplitudeOffset(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1GetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscGetAmplitudeOffset(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2GetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscGetAmplitudeOffset(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3GetAmplitudeOffset(scpi_t *context) {
    return RP_APP_OscGetAmplitudeOffset(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1SetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscSetAmplitudeScale(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2SetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscSetAmplitudeScale(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3SetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscSetAmplitudeScale(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1GetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscGetAmplitudeScale(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2GetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscGetAmplitudeScale(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3GetAmplitudeScale(scpi_t *context) {
    return RP_APP_OscGetAmplitudeScale(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1SetProbeAtt(scpi_t *context) {
    return RP_APP_OscSetProbeAtt(RP_CH_1, context);
}

scpi_result_t RP_APP_OscChannel2SetProbeAtt(scpi_t *context) {
    return RP_APP_OscSetProbeAtt(RP_CH_2, context);
}

scpi_result_t RP_APP_OscChannel1GetProbeAtt(scpi_t *context) {
    return RP_APP_OscGetProbeAtt(RP_CH_1, context);
}

scpi_result_t RP_APP_OscChannel2GetProbeAtt(scpi_t *context) {
    return RP_APP_OscGetProbeAtt(RP_CH_2, context);
}

scpi_result_t RP_APP_OscChannel1SetInputGain(scpi_t *context) {
    return RP_APP_OscSetInputGain(RP_CH_1, context);
}

scpi_result_t RP_APP_OscChannel2SetInputGain(scpi_t *context) {
    return RP_APP_OscSetInputGain(RP_CH_2, context);
}

scpi_result_t RP_APP_OscChannel1GetInputGain(scpi_t *context) {
    return RP_APP_OscGetInputGain(RP_CH_1, context);
}

scpi_result_t RP_APP_OscChannel2GetInputGain(scpi_t *context) {
    return RP_APP_OscGetInputGain(RP_CH_2, context);
}

scpi_result_t RP_APP_OscChannel1GetViewData(scpi_t *context) {
    return RP_APP_OscGetViewData(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2GetViewData(scpi_t *context) {
    return RP_APP_OscGetViewData(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3GetViewData(scpi_t *context) {
    return RP_APP_OscGetViewData(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureAmplitude(scpi_t *context) {
    return RP_APP_OscMeasureAmplitude(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureAmplitude(scpi_t *context) {
    return RP_APP_OscMeasureAmplitude(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureAmplitude(scpi_t *context) {
    return RP_APP_OscMeasureAmplitude(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureMeanVoltage(scpi_t *context) {
    return RP_APP_OscMeasureMeanVoltage(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureMeanVoltage(scpi_t *context) {
    return RP_APP_OscMeasureMeanVoltage(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureMeanVoltage(scpi_t *context) {
    return RP_APP_OscMeasureMeanVoltage(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureAmplitudeMax(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMax(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureAmplitudeMax(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMax(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureAmplitudeMax(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMax(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureAmplitudeMin(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMin(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureAmplitudeMin(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMin(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureAmplitudeMin(scpi_t *context) {
    return RP_APP_OscMeasureAmplitudeMin(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureFrequency(scpi_t *context) {
    return RP_APP_OscMeasureFrequency(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureFrequency(scpi_t *context) {
    return RP_APP_OscMeasureFrequency(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureFrequency(scpi_t *context) {
    return RP_APP_OscMeasureFrequency(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasurePeriod(scpi_t *context) {
    return RP_APP_OscMeasurePeriod(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasurePeriod(scpi_t *context) {
    return RP_APP_OscMeasurePeriod(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasurePeriod(scpi_t *context) {
    return RP_APP_OscMeasurePeriod(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1MeasureDutyCycle(scpi_t *context) {
    return RP_APP_OscMeasureDutyCycle(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2MeasureDutyCycle(scpi_t *context) {
    return RP_APP_OscMeasureDutyCycle(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3MeasureDutyCycle(scpi_t *context) {
    return RP_APP_OscMeasureDutyCycle(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1RMS(scpi_t *context) {
    return RP_APP_OscMeasureRMS(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2RMS(scpi_t *context) {
    return RP_APP_OscMeasureRMS(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3RMS(scpi_t *context) {
    return RP_APP_OscMeasureRMS(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscChannel1GetCursorVoltage(scpi_t *context) {
    return RP_APP_OscGetCursorVoltage(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2GetCursorVoltage(scpi_t *context) {
    return RP_APP_OscGetCursorVoltage(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3GetCursorVoltage(scpi_t *context) {
    return RP_APP_OscGetCursorVoltage(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscGetCursorTime(scpi_t *context) {
    uint32_t value;
    if (!SCPI_ParamUInt(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:CUR:T? is missing first parameter.");
        return SCPI_RES_ERR;
    }

    float resultValue;
    int result = rpApp_OscGetCursorTime(value, &resultValue);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CUR:T? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:CUR:T? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetCursorDeltaTime(scpi_t *context) {
    uint32_t cursor1;
    if (!SCPI_ParamUInt(context, &cursor1, true)) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DT? is missing first parameter.");
        return SCPI_RES_ERR;
    }
    uint32_t cursor2;
    if (!SCPI_ParamUInt(context, &cursor2, true)) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DT? is missing second parameter.");
        return SCPI_RES_ERR;
    }

    float resultValue;
    int result = rpApp_OscGetCursorDeltaTime(cursor1, cursor2, &resultValue);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DT? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, resultValue);
    syslog(LOG_INFO, "*OSC:CUR:CH<n>:DT? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscChannel1GetCursorDeltaAmplitude(scpi_t *context) {
    return RP_APP_OscGetCursorDeltaAmplitude(RPAPP_OSC_SOUR_CH1, context);
}

scpi_result_t RP_APP_OscChannel2GetCursorDeltaAmplitude(scpi_t *context) {
    return RP_APP_OscGetCursorDeltaAmplitude(RPAPP_OSC_SOUR_CH2, context);
}

scpi_result_t RP_APP_OscChannel3GetCursorDeltaAmplitude(scpi_t *context) {
    return RP_APP_OscGetCursorDeltaAmplitude(RPAPP_OSC_SOUR_MATH, context);
}

scpi_result_t RP_APP_OscGetCursorDeltaFrequency(scpi_t *context) {
    uint32_t cursor1;
    if (!SCPI_ParamUInt(context, &cursor1, true)) {
        syslog(LOG_ERR, "*OSC:CUR:DF? is missing first parameter.");
        return SCPI_RES_ERR;
    }
    uint32_t cursor2;
    if (!SCPI_ParamUInt(context, &cursor2, true)) {
        syslog(LOG_ERR, "*OSC:CUR:DF? is missing second parameter.");
        return SCPI_RES_ERR;
    }

    float resultValue;
    int result = rpApp_OscGetCursorDeltaFrequency(cursor1, cursor2, &resultValue);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CUR:DF? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, resultValue);
    syslog(LOG_INFO, "*OSC:CUR:DF? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetMathOperation(scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:MATH:OP is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rpApp_osc_math_oper_t op;
    if (getRpAppMathOperation(string, &op)) {
        syslog(LOG_ERR, "*OSC:MATH:OP parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetMathOperation(op);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MATH:OP Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:MATH:OP set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetMathOperation(scpi_t *context) {
    rpApp_osc_math_oper_t op;
    int result = rpApp_OscGetMathOperation(&op);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MATH:OP? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string[50];
    if (getRpAppMathOperationString(op, string)) {
        syslog(LOG_ERR, "*OSC:MATH:OP? failed to convert to string.");
        return SCPI_RES_ERR;
    }

    SCPI_ResultString(context, string);
    syslog(LOG_INFO, "*OSC:MATH:OP? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetMathSources(scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rp_channel_t s1;
    if (getRpChannel(string, &s1)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR parameter invalid.");
        return SCPI_RES_ERR;
    }

    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rp_channel_t s2;
    if (getRpChannel(string, &s2)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetMathSources(s1, s2);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:MATH:SOUR set successfully.");
    return SCPI_RES_OK;
}
scpi_result_t RP_APP_OscGetMathSources(scpi_t *context) {
    rp_channel_t s1, s2;
    int result = rpApp_OscGetMathSources(&s1, &s2);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string1[20], string2[20];
    if (getRpChannelString(s1, string1)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR? failed to convert to string.");
        return SCPI_RES_ERR;
    }
    if (getRpChannelString(s2, string2)) {
        syslog(LOG_ERR, "*OSC:MATH:SOUR? failed to convert to string.");
        return SCPI_RES_ERR;
    }

    SCPI_ResultString(context, strcat(string1, strcat(", ", string2)));
    syslog(LOG_INFO, "*OSC:MATH:SOUR? get successfully.");
    return SCPI_RES_OK;
}


scpi_result_t RP_APP_OscSetTimeOffset(scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTimeOffset((float) value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET Failed to set time offset: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TIME:OFFSET set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTimeOffset(scpi_t *context) {
    float value;
    int result = rpApp_OscGetTimeOffset(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:TIME:OFFSET? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetTimeScale(scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTimeScale((float) value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET Failed to set time offset: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TIME:OFFSET set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTimeScale(scpi_t *context) {
    float value;
    int result = rpApp_OscGetTimeScale(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TIME:SCALE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:TIME:SCALE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetTriggerSweep(scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:TRIG:SWEEP is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rpApp_osc_trig_sweep_t value;
    if (getRpAppTrigSweep(string, &value)) {
        syslog(LOG_ERR, "*OSC:TRIG:SWEEP parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTriggerSweep(value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:SWEEP Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TRIG:SWEEP set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTriggerSweep(scpi_t *context) {
    rpApp_osc_trig_sweep_t value;
    int result = rpApp_OscGetTriggerSweep(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string[20];
    if (getRpAppTrigSweepString(value, string)) {
        syslog(LOG_ERR, "*OSC:TIME:OFFSET? failed to convert to string.");
        return SCPI_RES_ERR;
    }


    SCPI_ResultString(context, string);
    syslog(LOG_INFO, "*OSC:TIME:OFFSET? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetTriggerSource(scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:TRIG:SOURCE is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rpApp_osc_trig_source_t value;
    if (getRpAppTrigSource(string, &value)) {
        syslog(LOG_ERR, "*OSC:TRIG:SOURCE parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTriggerSource(value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:SOURCE Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TRIG:SOURCE set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTriggerSource(scpi_t *context) {
    rpApp_osc_trig_source_t value;
    int result = rpApp_OscGetTriggerSource(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:SOURCE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string[20];
    if (getRpAppTrigSourceString(value, string)) {
        syslog(LOG_ERR, "*OSC:TRIG:SOURCE? failed to convert to string.");
        return SCPI_RES_ERR;
    }

    SCPI_ResultString(context, string);
    syslog(LOG_INFO, "*OSC:TRIG:SOURCE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetTriggerSlope(scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:TRIG:SLOPE is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rpApp_osc_trig_slope_t value;
    if (getRpAppTrigSlope(string, &value)) {
        syslog(LOG_ERR, "*OSC:TRIG:SLOPE parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTriggerSlope(value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:SLOPE Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TRIG:SLOPE set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTriggerSlope(scpi_t *context) {
    rpApp_osc_trig_slope_t value;
    int result = rpApp_OscGetTriggerSlope(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:SLOPE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string[50];
    if (getRpAppTrigSlopeString(value, string)) {
        syslog(LOG_ERR, "*OSC:TRIG:SLOPE? failed to convert to string.");
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:TRIG:SLOPE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetTriggerLevel(scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:TRIG:LEVEL is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetTriggerLevel((float) (value / 1000.0));
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:LEVEL Failed to set trigger level: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:TRIG:LEVEL set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetTriggerLevel(scpi_t *context) {
    float value;
    int result = rpApp_OscGetTriggerLevel(&value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:TRIG:LEVEL? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:TRIG:LEVEL? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetViewSize(scpi_t *context) {
    uint32_t value;
    if (!SCPI_ParamUInt(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:DATA:SIZE is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetViewSize(value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:DATA:SIZE Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:DATA:SIZE set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetViewSize(scpi_t *context) {
    uint32_t viewSize;
    int result = rpApp_OscGetViewSize(&viewSize);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:DATA:SIZE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultUInt(context, viewSize);
    syslog(LOG_INFO, "*OSC:DATA:SIZE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetViewPart(scpi_t *context) {
    float pos;
    int result = rpApp_OscGetViewPart(&pos);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:VIEW:PART? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, pos);
    syslog(LOG_INFO, "*OSC:VIEW:PART? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetAmplitudeOffset(rpApp_osc_source source, scpi_t *context) {
    double value;
    int result = rpApp_OscGetAmplitudeOffset(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:OFFSET? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:CH<n>:OFFSET? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetAmplitudeOffset(rpApp_osc_source source, scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:CH<n>:OFFSET is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetAmplitudeOffset(source, (float) value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:OFFSET Failed to set amplitude offset: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:CH<n>:OFFSET set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetAmplitudeScale(rpApp_osc_source source, scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:CH<n>:SCALE is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetAmplitudeScale(source, (float) value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:SCALE Failed to set amplitude scale: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:CH<n>:SCALE set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetAmplitudeScale(rpApp_osc_source source, scpi_t *context) {
    double value;
    int result = rpApp_OscGetAmplitudeScale(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:SCALE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:CH<n>:SCALE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetProbeAtt(rp_channel_t channel, scpi_t *context) {
    double value;
    if (!SCPI_ParamDouble(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:CH<n>:PROBE is missing first parameter.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetProbeAtt(channel, (float) value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:PROBE Failed: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:CH<n>:PROBE set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetProbeAtt(rp_channel_t channel, scpi_t *context) {
    float value;
    int result = rpApp_OscGetProbeAtt(channel, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:PROBE? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:CH<n>:PROBE? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscSetInputGain(rp_channel_t channel, scpi_t *context) {
    const char * param;
    size_t param_len;
    char string[25];
    if (!SCPI_ParamString(context, &param, &param_len, true)) {
        syslog(LOG_ERR, "*OSC:CH<n>:IN:GAIN is missing first parameter.");
        return SCPI_RES_ERR;
    }
    strncpy(string, param, param_len);
    string[param_len] = '\0';
    rpApp_osc_in_gain_t value;
    if (getRpAppInputGain(string, &value)) {
        syslog(LOG_ERR, "*OSC:CH<n>:IN:GAIN parameter invalid.");
        return SCPI_RES_ERR;
    }

    int result = rpApp_OscSetInputGain(channel, value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:IN:GAIN Failed to set: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:CH<n>:IN:GAIN set successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetInputGain(rp_channel_t channel, scpi_t *context) {
    rpApp_osc_in_gain_t value;
    int result = rpApp_OscGetInputGain(channel, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:IN:GAIN? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    char string[50];
    if (getRpAppInputGainString(value, string)) {
        syslog(LOG_ERR, "*OSC:CH<n>:IN:GAIN? failed to convert to string.");
        return SCPI_RES_ERR;
    }
    SCPI_ResultString(context, string);
    syslog(LOG_INFO, "*OSC:CH<n>:IN:GAIN? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetViewData(rpApp_osc_source source, scpi_t *context) {
    uint32_t viewSize;
    rpApp_OscGetViewSize(&viewSize);
    float data[viewSize];

    int result = rpApp_OscGetViewData(source, data, viewSize);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CH<n>:DATA? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultBufferFloat(context, data, viewSize);
    syslog(LOG_INFO, "*OSC:CH<n>:DATA? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureAmplitudeMin(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureAmplitudeMin(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:VMIN? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }

    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:VMIN? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureAmplitude(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureVpp(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:VPP? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:VPP? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureMeanVoltage(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureMeanVoltage(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:VMEAN? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:VMEAN? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureAmplitudeMax(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureAmplitudeMax(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:VMAX? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:VMAX? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureFrequency(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureFrequency(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:FREQ? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:FREQ? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasurePeriod(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasurePeriod(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:T0? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:T0? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureDutyCycle(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureDutyCycle(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:DCYC? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:DCYC? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscMeasureRMS(rpApp_osc_source source, scpi_t *context) {
    float value;
    int result = rpApp_OscMeasureRootMeanSquare(source, &value);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:MEAS:CH<n>:RMS? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:MEAS:CH<n>:RMS? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetCursorVoltage(rpApp_osc_source source, scpi_t *context) {
    uint32_t value;
    if (!SCPI_ParamUInt(context, &value, true)) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:V? is missing first parameter.");
        return SCPI_RES_ERR;
    }

    float resultValue;
    int result = rpApp_OscGetCursorVoltage(source, value, &resultValue);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:V? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, value);
    syslog(LOG_INFO, "*OSC:CUR:CH<n>:V? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscGetCursorDeltaAmplitude(rpApp_osc_source source, scpi_t *context) {
    uint32_t cursor1;
    if (!SCPI_ParamUInt(context, &cursor1, true)) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DV? is missing first parameter.");
        return SCPI_RES_ERR;
    }
    uint32_t cursor2;
    if (!SCPI_ParamUInt(context, &cursor2, true)) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DV? is missing second parameter.");
        return SCPI_RES_ERR;
    }

    float resultValue;
    int result = rpApp_OscGetCursorDeltaAmplitude(source, cursor1, cursor2, &resultValue);
    if (RP_OK != result) {
        syslog(LOG_ERR, "*OSC:CUR:CH<n>:DV? Failed to get: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    SCPI_ResultDouble(context, resultValue);
    syslog(LOG_INFO, "*OSC:CUR:CH<n>:DV? get successfully.");
    return SCPI_RES_OK;
}

scpi_result_t RP_APP_OscRunDigLoop(scpi_t *context){

    int result = rp_EnableDigitalLoop(true);
    if(result != RP_OK){
        syslog(LOG_ERR, "*OSC:RUN:DIGLOOP Failed to enable digital loop: %s", rp_GetError(result));
        return SCPI_RES_ERR;
    }
    syslog(LOG_INFO, "*OSC:RUN:DIGLOOP Successfully enabled Red Pitaya digital loop.");
    return SCPI_RES_OK;
}
