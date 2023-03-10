#include <open62541cpp/common/exception/exceptions_extended.hpp>

namespace opcua {
namespace diag {

void throw_from_status(uint32_t status_code) {
  if (status_code == 0) return;

  switch (status_code) {
    case 0x80010000: {
      throw(BadUnexpectedError());
      break;
    }
    case 0x80020000: {
      throw(BadInternalError());
      break;
    }
    case 0x80030000: {
      throw(BadOutOfMemory());
      break;
    }
    case 0x80040000: {
      throw(BadResourceUnavailable());
      break;
    }
    case 0x80050000: {
      throw(BadCommunicationError());
      break;
    }
    case 0x80060000: {
      throw(BadEncodingError());
      break;
    }
    case 0x80070000: {
      throw(BadDecodingError());
      break;
    }
    case 0x80080000: {
      throw(BadEncodingLimitsExceeded());
      break;
    }
    case 0x80B80000: {
      throw(BadRequestTooLarge());
      break;
    }
    case 0x80B90000: {
      throw(BadResponseTooLarge());
      break;
    }
    case 0x80090000: {
      throw(BadUnknownResponse());
      break;
    }
    case 0x800A0000: {
      throw(BadTimeout());
      break;
    }
    case 0x800B0000: {
      throw(BadServiceUnsupported());
      break;
    }
    case 0x800C0000: {
      throw(BadShutdown());
      break;
    }
    case 0x800D0000: {
      throw(BadServerNotConnected());
      break;
    }
    case 0x800E0000: {
      throw(BadServerHalted());
      break;
    }
    case 0x800F0000: {
      throw(BadNothingToDo());
      break;
    }
    case 0x80100000: {
      throw(BadTooManyOperations());
      break;
    }
    case 0x80DB0000: {
      throw(BadTooManyMonitoredItems());
      break;
    }
    case 0x80110000: {
      throw(BadDataTypeIdUnknown());
      break;
    }
    case 0x80120000: {
      throw(BadCertificateInvalid());
      break;
    }
    case 0x80130000: {
      throw(BadSecurityChecksFailed());
      break;
    }
    case 0x80140000: {
      throw(BadCertificateTimeInvalid());
      break;
    }
    case 0x80150000: {
      throw(BadCertificateIssuerTimeInvalid());
      break;
    }
    case 0x80160000: {
      throw(BadCertificateHostNameInvalid());
      break;
    }
    case 0x80170000: {
      throw(BadCertificateUriInvalid());
      break;
    }
    case 0x80180000: {
      throw(BadCertificateUseNotAllowed());
      break;
    }
    case 0x80190000: {
      throw(BadCertificateIssuerUseNotAllowed());
      break;
    }
    case 0x801A0000: {
      throw(BadCertificateUntrusted());
      break;
    }
    case 0x801B0000: {
      throw(BadCertificateRevocationUnknown());
      break;
    }
    case 0x801C0000: {
      throw(BadCertificateIssuerRevocationUnknown());
      break;
    }
    case 0x801D0000: {
      throw(BadCertificateRevoked());
      break;
    }
    case 0x801E0000: {
      throw(BadCertificateIssuerRevoked());
      break;
    }
    case 0x810D0000: {
      throw(BadCertificateChainIncomplete());
      break;
    }
    case 0x801F0000: {
      throw(BadUserAccessDenied());
      break;
    }
    case 0x80200000: {
      throw(BadIdentityTokenInvalid());
      break;
    }
    case 0x80210000: {
      throw(BadIdentityTokenRejected());
      break;
    }
    case 0x80220000: {
      throw(BadSecureChannelIdInvalid());
      break;
    }
    case 0x80230000: {
      throw(BadInvalidTimestamp());
      break;
    }
    case 0x80240000: {
      throw(BadNonceInvalid());
      break;
    }
    case 0x80250000: {
      throw(BadSessionIdInvalid());
      break;
    }
    case 0x80260000: {
      throw(BadSessionClosed());
      break;
    }
    case 0x80270000: {
      throw(BadSessionNotActivated());
      break;
    }
    case 0x80280000: {
      throw(BadSubscriptionIdInvalid());
      break;
    }
    case 0x802A0000: {
      throw(BadRequestHeaderInvalid());
      break;
    }
    case 0x802B0000: {
      throw(BadTimestampsToReturnInvalid());
      break;
    }
    case 0x802C0000: {
      throw(BadRequestCancelledByClient());
      break;
    }
    case 0x80E50000: {
      throw(BadTooManyArguments());
      break;
    }
    case 0x810E0000: {
      throw(BadLicenseExpired());
      break;
    }
    case 0x810F0000: {
      throw(BadLicenseLimitsExceeded());
      break;
    }
    case 0x81100000: {
      throw(BadLicenseNotAvailable());
      break;
    }
    case 0x002D0000: {
      throw(GoodSubscriptionTransferred());
      break;
    }
    case 0x002E0000: {
      throw(GoodCompletesAsynchronously());
      break;
    }
    case 0x002F0000: {
      throw(GoodOverload());
      break;
    }
    case 0x00300000: {
      throw(GoodClamped());
      break;
    }
    case 0x80310000: {
      throw(BadNoCommunication());
      break;
    }
    case 0x80320000: {
      throw(BadWaitingForInitialData());
      break;
    }
    case 0x80330000: {
      throw(BadNodeIdInvalid());
      break;
    }
    case 0x80340000: {
      throw(BadNodeIdUnknown());
      break;
    }
    case 0x80350000: {
      throw(BadAttributeIdInvalid());
      break;
    }
    case 0x80360000: {
      throw(BadIndexRangeInvalid());
      break;
    }
    case 0x80370000: {
      throw(BadIndexRangeNoData());
      break;
    }
    case 0x80380000: {
      throw(BadDataEncodingInvalid());
      break;
    }
    case 0x80390000: {
      throw(BadDataEncodingUnsupported());
      break;
    }
    case 0x803A0000: {
      throw(BadNotReadable());
      break;
    }
    case 0x803B0000: {
      throw(BadNotWritable());
      break;
    }
    case 0x803C0000: {
      throw(BadOutOfRange());
      break;
    }
    case 0x803D0000: {
      throw(BadNotSupported());
      break;
    }
    case 0x803E0000: {
      throw(BadNotFound());
      break;
    }
    case 0x803F0000: {
      throw(BadObjectDeleted());
      break;
    }
    case 0x80400000: {
      throw(BadNotImplemented());
      break;
    }
    case 0x80410000: {
      throw(BadMonitoringModeInvalid());
      break;
    }
    case 0x80420000: {
      throw(BadMonitoredItemIdInvalid());
      break;
    }
    case 0x80430000: {
      throw(BadMonitoredItemFilterInvalid());
      break;
    }
    case 0x80440000: {
      throw(BadMonitoredItemFilterUnsupported());
      break;
    }
    case 0x80450000: {
      throw(BadFilterNotAllowed());
      break;
    }
    case 0x80460000: {
      throw(BadStructureMissing());
      break;
    }
    case 0x80470000: {
      throw(BadEventFilterInvalid());
      break;
    }
    case 0x80480000: {
      throw(BadContentFilterInvalid());
      break;
    }
    case 0x80C10000: {
      throw(BadFilterOperatorInvalid());
      break;
    }
    case 0x80C20000: {
      throw(BadFilterOperatorUnsupported());
      break;
    }
    case 0x80C30000: {
      throw(BadFilterOperandCountMismatch());
      break;
    }
    case 0x80490000: {
      throw(BadFilterOperandInvalid());
      break;
    }
    case 0x80C40000: {
      throw(BadFilterElementInvalid());
      break;
    }
    case 0x80C50000: {
      throw(BadFilterLiteralInvalid());
      break;
    }
    case 0x804A0000: {
      throw(BadContinuationPointInvalid());
      break;
    }
    case 0x804B0000: {
      throw(BadNoContinuationPoints());
      break;
    }
    case 0x804C0000: {
      throw(BadReferenceTypeIdInvalid());
      break;
    }
    case 0x804D0000: {
      throw(BadBrowseDirectionInvalid());
      break;
    }
    case 0x804E0000: {
      throw(BadNodeNotInView());
      break;
    }
    case 0x804F0000: {
      throw(BadServerUriInvalid());
      break;
    }
    case 0x80500000: {
      throw(BadServerNameMissing());
      break;
    }
    case 0x80510000: {
      throw(BadDiscoveryUrlMissing());
      break;
    }
    case 0x80520000: {
      throw(BadSempahoreFileMissing());
      break;
    }
    case 0x80530000: {
      throw(BadRequestTypeInvalid());
      break;
    }
    case 0x80540000: {
      throw(BadSecurityModeRejected());
      break;
    }
    case 0x80550000: {
      throw(BadSecurityPolicyRejected());
      break;
    }
    case 0x80560000: {
      throw(BadTooManySessions());
      break;
    }
    case 0x80570000: {
      throw(BadUserSignatureInvalid());
      break;
    }
    case 0x80580000: {
      throw(BadApplicationSignatureInvalid());
      break;
    }
    case 0x80590000: {
      throw(BadNoValidCertificates());
      break;
    }
    case 0x80C60000: {
      throw(BadIdentityChangeNotSupported());
      break;
    }
    case 0x805A0000: {
      throw(BadRequestCancelledByRequest());
      break;
    }
    case 0x805B0000: {
      throw(BadParentNodeIdInvalid());
      break;
    }
    case 0x805C0000: {
      throw(BadReferenceNotAllowed());
      break;
    }
    case 0x805D0000: {
      throw(BadNodeIdRejected());
      break;
    }
    case 0x805E0000: {
      throw(BadNodeIdExists());
      break;
    }
    case 0x805F0000: {
      throw(BadNodeClassInvalid());
      break;
    }
    case 0x80600000: {
      throw(BadBrowseNameInvalid());
      break;
    }
    case 0x80610000: {
      throw(BadBrowseNameDuplicated());
      break;
    }
    case 0x80620000: {
      throw(BadNodeAttributesInvalid());
      break;
    }
    case 0x80630000: {
      throw(BadTypeDefinitionInvalid());
      break;
    }
    case 0x80640000: {
      throw(BadSourceNodeIdInvalid());
      break;
    }
    case 0x80650000: {
      throw(BadTargetNodeIdInvalid());
      break;
    }
    case 0x80660000: {
      throw(BadDuplicateReferenceNotAllowed());
      break;
    }
    case 0x80670000: {
      throw(BadInvalidSelfReference());
      break;
    }
    case 0x80680000: {
      throw(BadReferenceLocalOnly());
      break;
    }
    case 0x80690000: {
      throw(BadNoDeleteRights());
      break;
    }
    case 0x40BC0000: {
      throw(UncertainReferenceNotDeleted());
      break;
    }
    case 0x806A0000: {
      throw(BadServerIndexInvalid());
      break;
    }
    case 0x806B0000: {
      throw(BadViewIdUnknown());
      break;
    }
    case 0x80C90000: {
      throw(BadViewTimestampInvalid());
      break;
    }
    case 0x80CA0000: {
      throw(BadViewParameterMismatch());
      break;
    }
    case 0x80CB0000: {
      throw(BadViewVersionInvalid());
      break;
    }
    case 0x40C00000: {
      throw(UncertainNotAllNodesAvailable());
      break;
    }
    case 0x00BA0000: {
      throw(GoodResultsMayBeIncomplete());
      break;
    }
    case 0x80C80000: {
      throw(BadNotTypeDefinition());
      break;
    }
    case 0x406C0000: {
      throw(UncertainReferenceOutOfServer());
      break;
    }
    case 0x806D0000: {
      throw(BadTooManyMatches());
      break;
    }
    case 0x806E0000: {
      throw(BadQueryTooComplex());
      break;
    }
    case 0x806F0000: {
      throw(BadNoMatch());
      break;
    }
    case 0x80700000: {
      throw(BadMaxAgeInvalid());
      break;
    }
    case 0x80E60000: {
      throw(BadSecurityModeInsufficient());
      break;
    }
    case 0x80710000: {
      throw(BadHistoryOperationInvalid());
      break;
    }
    case 0x80720000: {
      throw(BadHistoryOperationUnsupported());
      break;
    }
    case 0x80BD0000: {
      throw(BadInvalidTimestampArgument());
      break;
    }
    case 0x80730000: {
      throw(BadWriteNotSupported());
      break;
    }
    case 0x80740000: {
      throw(BadTypeMismatch());
      break;
    }
    case 0x80750000: {
      throw(BadMethodInvalid());
      break;
    }
    case 0x80760000: {
      throw(BadArgumentsMissing());
      break;
    }
    case 0x80770000: {
      throw(BadTooManySubscriptions());
      break;
    }
    case 0x80780000: {
      throw(BadTooManyPublishRequests());
      break;
    }
    case 0x80790000: {
      throw(BadNoSubscription());
      break;
    }
    case 0x807A0000: {
      throw(BadSequenceNumberUnknown());
      break;
    }
    case 0x807B0000: {
      throw(BadMessageNotAvailable());
      break;
    }
    case 0x807C0000: {
      throw(BadInsufficientClientProfile());
      break;
    }
    case 0x80BF0000: {
      throw(BadStateNotActive());
      break;
    }
    case 0x807D0000: {
      throw(BadTcpServerTooBusy());
      break;
    }
    case 0x807E0000: {
      throw(BadTcpMessageTypeInvalid());
      break;
    }
    case 0x807F0000: {
      throw(BadTcpSecureChannelUnknown());
      break;
    }
    case 0x80800000: {
      throw(BadTcpMessageTooLarge());
      break;
    }
    case 0x80810000: {
      throw(BadTcpNotEnoughResources());
      break;
    }
    case 0x80820000: {
      throw(BadTcpInternalError());
      break;
    }
    case 0x80830000: {
      throw(BadTcpEndpointUrlInvalid());
      break;
    }
    case 0x80840000: {
      throw(BadRequestInterrupted());
      break;
    }
    case 0x80850000: {
      throw(BadRequestTimeout());
      break;
    }
    case 0x80860000: {
      throw(BadSecureChannelClosed());
      break;
    }
    case 0x80870000: {
      throw(BadSecureChannelTokenUnknown());
      break;
    }
    case 0x80880000: {
      throw(BadSequenceNumberInvalid());
      break;
    }
    case 0x80BE0000: {
      throw(BadProtocolVersionUnsupported());
      break;
    }
    case 0x80890000: {
      throw(BadConfigurationError());
      break;
    }
    case 0x808A0000: {
      throw(BadNotConnected());
      break;
    }
    case 0x808B0000: {
      throw(BadDeviceFailure());
      break;
    }
    case 0x808C0000: {
      throw(BadSensorFailure());
      break;
    }
    case 0x808D0000: {
      throw(BadOutOfService());
      break;
    }
    case 0x808E0000: {
      throw(BadDeadbandFilterInvalid());
      break;
    }
    case 0x408F0000: {
      throw(UncertainNoCommunicationLastUsableValue());
      break;
    }
    case 0x40900000: {
      throw(UncertainLastUsableValue());
      break;
    }
    case 0x40910000: {
      throw(UncertainSubstituteValue());
      break;
    }
    case 0x40920000: {
      throw(UncertainInitialValue());
      break;
    }
    case 0x40930000: {
      throw(UncertainSensorNotAccurate());
      break;
    }
    case 0x40940000: {
      throw(UncertainEngineeringUnitsExceeded());
      break;
    }
    case 0x40950000: {
      throw(UncertainSubNormal());
      break;
    }
    case 0x00960000: {
      throw(GoodLocalOverride());
      break;
    }
    case 0x80970000: {
      throw(BadRefreshInProgress());
      break;
    }
    case 0x80980000: {
      throw(BadConditionAlreadyDisabled());
      break;
    }
    case 0x80CC0000: {
      throw(BadConditionAlreadyEnabled());
      break;
    }
    case 0x80990000: {
      throw(BadConditionDisabled());
      break;
    }
    case 0x809A0000: {
      throw(BadEventIdUnknown());
      break;
    }
    case 0x80BB0000: {
      throw(BadEventNotAcknowledgeable());
      break;
    }
    case 0x80CD0000: {
      throw(BadDialogNotActive());
      break;
    }
    case 0x80CE0000: {
      throw(BadDialogResponseInvalid());
      break;
    }
    case 0x80CF0000: {
      throw(BadConditionBranchAlreadyAcked());
      break;
    }
    case 0x80D00000: {
      throw(BadConditionBranchAlreadyConfirmed());
      break;
    }
    case 0x80D10000: {
      throw(BadConditionAlreadyShelved());
      break;
    }
    case 0x80D20000: {
      throw(BadConditionNotShelved());
      break;
    }
    case 0x80D30000: {
      throw(BadShelvingTimeOutOfRange());
      break;
    }
    case 0x809B0000: {
      throw(BadNoData());
      break;
    }
    case 0x80D70000: {
      throw(BadBoundNotFound());
      break;
    }
    case 0x80D80000: {
      throw(BadBoundNotSupported());
      break;
    }
    case 0x809D0000: {
      throw(BadDataLost());
      break;
    }
    case 0x809E0000: {
      throw(BadDataUnavailable());
      break;
    }
    case 0x809F0000: {
      throw(BadEntryExists());
      break;
    }
    case 0x80A00000: {
      throw(BadNoEntryExists());
      break;
    }
    case 0x80A10000: {
      throw(BadTimestampNotSupported());
      break;
    }
    case 0x00A20000: {
      throw(GoodEntryInserted());
      break;
    }
    case 0x00A30000: {
      throw(GoodEntryReplaced());
      break;
    }
    case 0x40A40000: {
      throw(UncertainDataSubNormal());
      break;
    }
    case 0x00A50000: {
      throw(GoodNoData());
      break;
    }
    case 0x00A60000: {
      throw(GoodMoreData());
      break;
    }
    case 0x80D40000: {
      throw(BadAggregateListMismatch());
      break;
    }
    case 0x80D50000: {
      throw(BadAggregateNotSupported());
      break;
    }
    case 0x80D60000: {
      throw(BadAggregateInvalidInputs());
      break;
    }
    case 0x80DA0000: {
      throw(BadAggregateConfigurationRejected());
      break;
    }
    case 0x00D90000: {
      throw(GoodDataIgnored());
      break;
    }
    case 0x80E40000: {
      throw(BadRequestNotAllowed());
      break;
    }
    case 0x00DC0000: {
      throw(GoodEdited());
      break;
    }
    case 0x00DD0000: {
      throw(GoodPostActionFailed());
      break;
    }
    case 0x40DE0000: {
      throw(UncertainDominantValueChanged());
      break;
    }
    case 0x00E00000: {
      throw(GoodDependentValueChanged());
      break;
    }
    case 0x80E10000: {
      throw(BadDominantValueChanged());
      break;
    }
    case 0x40E20000: {
      throw(UncertainDependentValueChanged());
      break;
    }
    case 0x80E30000: {
      throw(BadDependentValueChanged());
      break;
    }
    case 0x00A70000: {
      throw(GoodCommunicationEvent());
      break;
    }
    case 0x00A80000: {
      throw(GoodShutdownEvent());
      break;
    }
    case 0x00A90000: {
      throw(GoodCallAgain());
      break;
    }
    case 0x00AA0000: {
      throw(GoodNonCriticalTimeout());
      break;
    }
    case 0x80AB0000: {
      throw(BadInvalidArgument());
      break;
    }
    case 0x80AC0000: {
      throw(BadConnectionRejected());
      break;
    }
    case 0x80AD0000: {
      throw(BadDisconnect());
      break;
    }
    case 0x80AE0000: {
      throw(BadConnectionClosed());
      break;
    }
    case 0x80AF0000: {
      throw(BadInvalidState());
      break;
    }
    case 0x80B00000: {
      throw(BadEndOfStream());
      break;
    }
    case 0x80B10000: {
      throw(BadNoDataAvailable());
      break;
    }
    case 0x80B20000: {
      throw(BadWaitingForResponse());
      break;
    }
    case 0x80B30000: {
      throw(BadOperationAbandoned());
      break;
    }
    case 0x80B40000: {
      throw(BadExpectedStreamToBlock());
      break;
    }
    case 0x80B50000: {
      throw(BadWouldBlock());
      break;
    }
    case 0x80B60000: {
      throw(BadSyntaxError());
      break;
    }
    case 0x80B70000: {
      throw(BadMaxConnectionsReached());
      break;
    }
    default: {
      throw(OpcuaUnknownException());
      break;
    }
  }
}

const char* get_status_description_string(uint32_t status_code) {
  auto val = status_description_table.find(status_code);
  if (val == nullptr) return "Unknown error";
  return val->second;
}

}  // namespace diag
}  // namespace opcua