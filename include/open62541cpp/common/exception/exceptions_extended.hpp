#ifndef EXCEPTIONS_EXTENDED_HPP
#define EXCEPTIONS_EXTENDED_HPP

// The exceptions are created from  V1.04 OPC-UA status codes spec below
// https://github.com/OPCFoundation/UA-.NET-Legacy/blob/master/Stack/Core/Schema/Opc.Ua.StatusCodes.csv

#include <open62541cpp/common/exception/exceptions_core.hpp>
#include <string>
#include <unordered_map>

namespace opcua {
namespace diag {

class BadUnexpectedError : public BadStatusException {
 private:
  const char* msg_ = "An unexpected error occurred.";
  const uint32_t status = 0x80010000;

 public:
  BadUnexpectedError() = default;
  virtual ~BadUnexpectedError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInternalError : public BadStatusException {
 private:
  const char* msg_ =
      "An internal error occurred as a result of a programming or "
      "configuration error.";
  const uint32_t status = 0x80020000;

 public:
  BadInternalError() = default;
  virtual ~BadInternalError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadOutOfMemory : public BadStatusException {
 private:
  const char* msg_ = "Not enough memory to complete the operation.";
  const uint32_t status = 0x80030000;

 public:
  BadOutOfMemory() = default;
  virtual ~BadOutOfMemory() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadResourceUnavailable : public BadStatusException {
 private:
  const char* msg_ = "An operating system resource is not available.";
  const uint32_t status = 0x80040000;

 public:
  BadResourceUnavailable() = default;
  virtual ~BadResourceUnavailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCommunicationError : public BadStatusException {
 private:
  const char* msg_ = "A low level communication error occurred.";
  const uint32_t status = 0x80050000;

 public:
  BadCommunicationError() = default;
  virtual ~BadCommunicationError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEncodingError : public BadStatusException {
 private:
  const char* msg_ =
      "Encoding halted because of invalid data in the objects being "
      "serialized.";
  const uint32_t status = 0x80060000;

 public:
  BadEncodingError() = default;
  virtual ~BadEncodingError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDecodingError : public BadStatusException {
 private:
  const char* msg_ = "Decoding halted because of invalid data in the stream.";
  const uint32_t status = 0x80070000;

 public:
  BadDecodingError() = default;
  virtual ~BadDecodingError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEncodingLimitsExceeded : public BadStatusException {
 private:
  const char* msg_ =
      "The message encoding/decoding limits imposed by the stack have been "
      "exceeded.";
  const uint32_t status = 0x80080000;

 public:
  BadEncodingLimitsExceeded() = default;
  virtual ~BadEncodingLimitsExceeded() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestTooLarge : public BadStatusException {
 private:
  const char* msg_ =
      "The request message size exceeds limits set by the server.";
  const uint32_t status = 0x80B80000;

 public:
  BadRequestTooLarge() = default;
  virtual ~BadRequestTooLarge() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadResponseTooLarge : public BadStatusException {
 private:
  const char* msg_ =
      "The response message size exceeds limits set by the client.";
  const uint32_t status = 0x80B90000;

 public:
  BadResponseTooLarge() = default;
  virtual ~BadResponseTooLarge() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadUnknownResponse : public BadStatusException {
 private:
  const char* msg_ = "An unrecognized response was received from the server.";
  const uint32_t status = 0x80090000;

 public:
  BadUnknownResponse() = default;
  virtual ~BadUnknownResponse() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTimeout : public BadStatusException {
 private:
  const char* msg_ = "The operation timed out.";
  const uint32_t status = 0x800A0000;

 public:
  BadTimeout() = default;
  virtual ~BadTimeout() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServiceUnsupported : public BadStatusException {
 private:
  const char* msg_ = "The server does not support the requested service.";
  const uint32_t status = 0x800B0000;

 public:
  BadServiceUnsupported() = default;
  virtual ~BadServiceUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadShutdown : public BadStatusException {
 private:
  const char* msg_ =
      "The operation was cancelled because the application is shutting down.";
  const uint32_t status = 0x800C0000;

 public:
  BadShutdown() = default;
  virtual ~BadShutdown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServerNotConnected : public BadStatusException {
 private:
  const char* msg_ =
      "The operation could not complete because the client is not connected to "
      "the server.";
  const uint32_t status = 0x800D0000;

 public:
  BadServerNotConnected() = default;
  virtual ~BadServerNotConnected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServerHalted : public BadStatusException {
 private:
  const char* msg_ = "The server has stopped and cannot process any requests.";
  const uint32_t status = 0x800E0000;

 public:
  BadServerHalted() = default;
  virtual ~BadServerHalted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNothingToDo : public BadStatusException {
 private:
  const char* msg_ =
      "There was nothing to do because the client passed a list of operations "
      "with no elements.";
  const uint32_t status = 0x800F0000;

 public:
  BadNothingToDo() = default;
  virtual ~BadNothingToDo() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManyOperations : public BadStatusException {
 private:
  const char* msg_ =
      "The request could not be processed because it specified too many "
      "operations.";
  const uint32_t status = 0x80100000;

 public:
  BadTooManyOperations() = default;
  virtual ~BadTooManyOperations() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManyMonitoredItems : public BadStatusException {
 private:
  const char* msg_ =
      "The request could not be processed because there are too many monitored "
      "items in the subscription.";
  const uint32_t status = 0x80DB0000;

 public:
  BadTooManyMonitoredItems() = default;
  virtual ~BadTooManyMonitoredItems() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDataTypeIdUnknown : public BadStatusException {
 private:
  const char* msg_ =
      "The extension object cannot be (de)serialized because the data type id "
      "is not recognized.";
  const uint32_t status = 0x80110000;

 public:
  BadDataTypeIdUnknown() = default;
  virtual ~BadDataTypeIdUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateInvalid : public BadStatusException {
 private:
  const char* msg_ = "The certificate provided as a parameter is not valid.";
  const uint32_t status = 0x80120000;

 public:
  BadCertificateInvalid() = default;
  virtual ~BadCertificateInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecurityChecksFailed : public BadStatusException {
 private:
  const char* msg_ = "An error occurred verifying security.";
  const uint32_t status = 0x80130000;

 public:
  BadSecurityChecksFailed() = default;
  virtual ~BadSecurityChecksFailed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateTimeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The certificate has expired or is not yet valid.";
  const uint32_t status = 0x80140000;

 public:
  BadCertificateTimeInvalid() = default;
  virtual ~BadCertificateTimeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateIssuerTimeInvalid : public BadStatusException {
 private:
  const char* msg_ = "An issuer certificate has expired or is not yet valid.";
  const uint32_t status = 0x80150000;

 public:
  BadCertificateIssuerTimeInvalid() = default;
  virtual ~BadCertificateIssuerTimeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateHostNameInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The HostName used to connect to a server does not match a HostName in "
      "the certificate.";
  const uint32_t status = 0x80160000;

 public:
  BadCertificateHostNameInvalid() = default;
  virtual ~BadCertificateHostNameInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateUriInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The URI specified in the ApplicationDescription does not match the URI "
      "in the certificate.";
  const uint32_t status = 0x80170000;

 public:
  BadCertificateUriInvalid() = default;
  virtual ~BadCertificateUriInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateUseNotAllowed : public BadStatusException {
 private:
  const char* msg_ =
      "The certificate may not be used for the requested operation.";
  const uint32_t status = 0x80180000;

 public:
  BadCertificateUseNotAllowed() = default;
  virtual ~BadCertificateUseNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateIssuerUseNotAllowed : public BadStatusException {
 private:
  const char* msg_ =
      "The issuer certificate may not be used for the requested operation.";
  const uint32_t status = 0x80190000;

 public:
  BadCertificateIssuerUseNotAllowed() = default;
  virtual ~BadCertificateIssuerUseNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateUntrusted : public BadStatusException {
 private:
  const char* msg_ = "The certificate is not trusted.";
  const uint32_t status = 0x801A0000;

 public:
  BadCertificateUntrusted() = default;
  virtual ~BadCertificateUntrusted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateRevocationUnknown : public BadStatusException {
 private:
  const char* msg_ =
      "It was not possible to determine if the certificate has been revoked.";
  const uint32_t status = 0x801B0000;

 public:
  BadCertificateRevocationUnknown() = default;
  virtual ~BadCertificateRevocationUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateIssuerRevocationUnknown : public BadStatusException {
 private:
  const char* msg_ =
      "It was not possible to determine if the issuer certificate has been "
      "revoked.";
  const uint32_t status = 0x801C0000;

 public:
  BadCertificateIssuerRevocationUnknown() = default;
  virtual ~BadCertificateIssuerRevocationUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateRevoked : public BadStatusException {
 private:
  const char* msg_ = "The certificate has been revoked.";
  const uint32_t status = 0x801D0000;

 public:
  BadCertificateRevoked() = default;
  virtual ~BadCertificateRevoked() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateIssuerRevoked : public BadStatusException {
 private:
  const char* msg_ = "The issuer certificate has been revoked.";
  const uint32_t status = 0x801E0000;

 public:
  BadCertificateIssuerRevoked() = default;
  virtual ~BadCertificateIssuerRevoked() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadCertificateChainIncomplete : public BadStatusException {
 private:
  const char* msg_ = "The certificate chain is incomplete.";
  const uint32_t status = 0x810D0000;

 public:
  BadCertificateChainIncomplete() = default;
  virtual ~BadCertificateChainIncomplete() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadUserAccessDenied : public BadStatusException {
 private:
  const char* msg_ =
      "User does not have permission to perform the requested operation.";
  const uint32_t status = 0x801F0000;

 public:
  BadUserAccessDenied() = default;
  virtual ~BadUserAccessDenied() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadIdentityTokenInvalid : public BadStatusException {
 private:
  const char* msg_ = "The user identity token is not valid.";
  const uint32_t status = 0x80200000;

 public:
  BadIdentityTokenInvalid() = default;
  virtual ~BadIdentityTokenInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadIdentityTokenRejected : public BadStatusException {
 private:
  const char* msg_ =
      "The user identity token is valid but the server has rejected it.";
  const uint32_t status = 0x80210000;

 public:
  BadIdentityTokenRejected() = default;
  virtual ~BadIdentityTokenRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecureChannelIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The specified secure channel is no longer valid.";
  const uint32_t status = 0x80220000;

 public:
  BadSecureChannelIdInvalid() = default;
  virtual ~BadSecureChannelIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInvalidTimestamp : public BadStatusException {
 private:
  const char* msg_ =
      "The timestamp is outside the range allowed by the server.";
  const uint32_t status = 0x80230000;

 public:
  BadInvalidTimestamp() = default;
  virtual ~BadInvalidTimestamp() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNonceInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The nonce does appear to be not a random value or it is not the correct "
      "length.";
  const uint32_t status = 0x80240000;

 public:
  BadNonceInvalid() = default;
  virtual ~BadNonceInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSessionIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The session id is not valid.";
  const uint32_t status = 0x80250000;

 public:
  BadSessionIdInvalid() = default;
  virtual ~BadSessionIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSessionClosed : public BadStatusException {
 private:
  const char* msg_ = "The session was closed by the client.";
  const uint32_t status = 0x80260000;

 public:
  BadSessionClosed() = default;
  virtual ~BadSessionClosed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSessionNotActivated : public BadStatusException {
 private:
  const char* msg_ =
      "The session cannot be used because ActivateSession has not been called.";
  const uint32_t status = 0x80270000;

 public:
  BadSessionNotActivated() = default;
  virtual ~BadSessionNotActivated() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSubscriptionIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The subscription id is not valid.";
  const uint32_t status = 0x80280000;

 public:
  BadSubscriptionIdInvalid() = default;
  virtual ~BadSubscriptionIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestHeaderInvalid : public BadStatusException {
 private:
  const char* msg_ = "The header for the request is missing or invalid.";
  const uint32_t status = 0x802A0000;

 public:
  BadRequestHeaderInvalid() = default;
  virtual ~BadRequestHeaderInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTimestampsToReturnInvalid : public BadStatusException {
 private:
  const char* msg_ = "The timestamps to return parameter is invalid.";
  const uint32_t status = 0x802B0000;

 public:
  BadTimestampsToReturnInvalid() = default;
  virtual ~BadTimestampsToReturnInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestCancelledByClient : public BadStatusException {
 private:
  const char* msg_ = "The request was cancelled by the client.";
  const uint32_t status = 0x802C0000;

 public:
  BadRequestCancelledByClient() = default;
  virtual ~BadRequestCancelledByClient() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManyArguments : public BadStatusException {
 private:
  const char* msg_ = "Too many arguments were provided.";
  const uint32_t status = 0x80E50000;

 public:
  BadTooManyArguments() = default;
  virtual ~BadTooManyArguments() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadLicenseExpired : public BadStatusException {
 private:
  const char* msg_ =
      "The server requires a license to operate in general or to perform a "
      "service or operation";
  const uint32_t status = 0x810E0000;

 public:
  BadLicenseExpired() = default;
  virtual ~BadLicenseExpired() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadLicenseLimitsExceeded : public BadStatusException {
 private:
  const char* msg_ =
      "The server has limits on number of allowed operations / objects";
  const uint32_t status = 0x810F0000;

 public:
  BadLicenseLimitsExceeded() = default;
  virtual ~BadLicenseLimitsExceeded() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadLicenseNotAvailable : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not have a license which is required to operate in "
      "general or to perform a service or operation.";
  const uint32_t status = 0x81100000;

 public:
  BadLicenseNotAvailable() = default;
  virtual ~BadLicenseNotAvailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodSubscriptionTransferred : public GoodStatusException {
 private:
  const char* msg_ = "The subscription was transferred to another session.";
  const uint32_t status = 0x002D0000;

 public:
  GoodSubscriptionTransferred() = default;
  virtual ~GoodSubscriptionTransferred() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodCompletesAsynchronously : public GoodStatusException {
 private:
  const char* msg_ = "The processing will complete asynchronously.";
  const uint32_t status = 0x002E0000;

 public:
  GoodCompletesAsynchronously() = default;
  virtual ~GoodCompletesAsynchronously() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodOverload : public GoodStatusException {
 private:
  const char* msg_ = "Sampling has slowed down due to resource limitations.";
  const uint32_t status = 0x002F0000;

 public:
  GoodOverload() = default;
  virtual ~GoodOverload() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodClamped : public GoodStatusException {
 private:
  const char* msg_ = "The value written was accepted but was clamped.";
  const uint32_t status = 0x00300000;

 public:
  GoodClamped() = default;
  virtual ~GoodClamped() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoCommunication : public BadStatusException {
 private:
  const char* msg_ = "Communication with the data source is defined";
  const uint32_t status = 0x80310000;

 public:
  BadNoCommunication() = default;
  virtual ~BadNoCommunication() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadWaitingForInitialData : public BadStatusException {
 private:
  const char* msg_ =
      "Waiting for the server to obtain values from the underlying data "
      "source.";
  const uint32_t status = 0x80320000;

 public:
  BadWaitingForInitialData() = default;
  virtual ~BadWaitingForInitialData() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The syntax of the node id is not valid.";
  const uint32_t status = 0x80330000;

 public:
  BadNodeIdInvalid() = default;
  virtual ~BadNodeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeIdUnknown : public BadStatusException {
 private:
  const char* msg_ =
      "The node id refers to a node that does not exist in the server address "
      "space.";
  const uint32_t status = 0x80340000;

 public:
  BadNodeIdUnknown() = default;
  virtual ~BadNodeIdUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadAttributeIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The attribute is not supported for the specified Node.";
  const uint32_t status = 0x80350000;

 public:
  BadAttributeIdInvalid() = default;
  virtual ~BadAttributeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadIndexRangeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The syntax of the index range parameter is invalid.";
  const uint32_t status = 0x80360000;

 public:
  BadIndexRangeInvalid() = default;
  virtual ~BadIndexRangeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadIndexRangeNoData : public BadStatusException {
 private:
  const char* msg_ = "No data exists within the range of indexes specified.";
  const uint32_t status = 0x80370000;

 public:
  BadIndexRangeNoData() = default;
  virtual ~BadIndexRangeNoData() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDataEncodingInvalid : public BadStatusException {
 private:
  const char* msg_ = "The data encoding is invalid.";
  const uint32_t status = 0x80380000;

 public:
  BadDataEncodingInvalid() = default;
  virtual ~BadDataEncodingInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDataEncodingUnsupported : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not support the requested data encoding for the node.";
  const uint32_t status = 0x80390000;

 public:
  BadDataEncodingUnsupported() = default;
  virtual ~BadDataEncodingUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotReadable : public BadStatusException {
 private:
  const char* msg_ =
      "The access level does not allow reading or subscribing to the Node.";
  const uint32_t status = 0x803A0000;

 public:
  BadNotReadable() = default;
  virtual ~BadNotReadable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotWritable : public BadStatusException {
 private:
  const char* msg_ = "The access level does not allow writing to the Node.";
  const uint32_t status = 0x803B0000;

 public:
  BadNotWritable() = default;
  virtual ~BadNotWritable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadOutOfRange : public BadStatusException {
 private:
  const char* msg_ = "The value was out of range.";
  const uint32_t status = 0x803C0000;

 public:
  BadOutOfRange() = default;
  virtual ~BadOutOfRange() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotSupported : public BadStatusException {
 private:
  const char* msg_ = "The requested operation is not supported.";
  const uint32_t status = 0x803D0000;

 public:
  BadNotSupported() = default;
  virtual ~BadNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotFound : public BadStatusException {
 private:
  const char* msg_ =
      "A requested item was not found or a search operation ended without "
      "success.";
  const uint32_t status = 0x803E0000;

 public:
  BadNotFound() = default;
  virtual ~BadNotFound() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadObjectDeleted : public BadStatusException {
 private:
  const char* msg_ = "The object cannot be used because it has been deleted.";
  const uint32_t status = 0x803F0000;

 public:
  BadObjectDeleted() = default;
  virtual ~BadObjectDeleted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotImplemented : public BadStatusException {
 private:
  const char* msg_ = "Requested operation is not implemented.";
  const uint32_t status = 0x80400000;

 public:
  BadNotImplemented() = default;
  virtual ~BadNotImplemented() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMonitoringModeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The monitoring mode is invalid.";
  const uint32_t status = 0x80410000;

 public:
  BadMonitoringModeInvalid() = default;
  virtual ~BadMonitoringModeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMonitoredItemIdInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The monitoring item id does not refer to a valid monitored item.";
  const uint32_t status = 0x80420000;

 public:
  BadMonitoredItemIdInvalid() = default;
  virtual ~BadMonitoredItemIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMonitoredItemFilterInvalid : public BadStatusException {
 private:
  const char* msg_ = "The monitored item filter parameter is not valid.";
  const uint32_t status = 0x80430000;

 public:
  BadMonitoredItemFilterInvalid() = default;
  virtual ~BadMonitoredItemFilterInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMonitoredItemFilterUnsupported : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not support the requested monitored item filter.";
  const uint32_t status = 0x80440000;

 public:
  BadMonitoredItemFilterUnsupported() = default;
  virtual ~BadMonitoredItemFilterUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterNotAllowed : public BadStatusException {
 private:
  const char* msg_ =
      "A monitoring filter cannot be used in combination with the attribute "
      "specified.";
  const uint32_t status = 0x80450000;

 public:
  BadFilterNotAllowed() = default;
  virtual ~BadFilterNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadStructureMissing : public BadStatusException {
 private:
  const char* msg_ = "A mandatory structured parameter was missing or null.";
  const uint32_t status = 0x80460000;

 public:
  BadStructureMissing() = default;
  virtual ~BadStructureMissing() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEventFilterInvalid : public BadStatusException {
 private:
  const char* msg_ = "The event filter is not valid.";
  const uint32_t status = 0x80470000;

 public:
  BadEventFilterInvalid() = default;
  virtual ~BadEventFilterInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadContentFilterInvalid : public BadStatusException {
 private:
  const char* msg_ = "The content filter is not valid.";
  const uint32_t status = 0x80480000;

 public:
  BadContentFilterInvalid() = default;
  virtual ~BadContentFilterInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterOperatorInvalid : public BadStatusException {
 private:
  const char* msg_ = "An unregognized operator was provided in a filter.";
  const uint32_t status = 0x80C10000;

 public:
  BadFilterOperatorInvalid() = default;
  virtual ~BadFilterOperatorInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterOperatorUnsupported : public BadStatusException {
 private:
  const char* msg_ = "A valid operator was provided";
  const uint32_t status = 0x80C20000;

 public:
  BadFilterOperatorUnsupported() = default;
  virtual ~BadFilterOperatorUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterOperandCountMismatch : public BadStatusException {
 private:
  const char* msg_ =
      "The number of operands provided for the filter operator was less then "
      "expected for the operand provided.";
  const uint32_t status = 0x80C30000;

 public:
  BadFilterOperandCountMismatch() = default;
  virtual ~BadFilterOperandCountMismatch() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterOperandInvalid : public BadStatusException {
 private:
  const char* msg_ = "The operand used in a content filter is not valid.";
  const uint32_t status = 0x80490000;

 public:
  BadFilterOperandInvalid() = default;
  virtual ~BadFilterOperandInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterElementInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The referenced element is not a valid element in the content filter.";
  const uint32_t status = 0x80C40000;

 public:
  BadFilterElementInvalid() = default;
  virtual ~BadFilterElementInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadFilterLiteralInvalid : public BadStatusException {
 private:
  const char* msg_ = "The referenced literal is not a valid value.";
  const uint32_t status = 0x80C50000;

 public:
  BadFilterLiteralInvalid() = default;
  virtual ~BadFilterLiteralInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadContinuationPointInvalid : public BadStatusException {
 private:
  const char* msg_ = "The continuation point provide is longer valid.";
  const uint32_t status = 0x804A0000;

 public:
  BadContinuationPointInvalid() = default;
  virtual ~BadContinuationPointInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoContinuationPoints : public BadStatusException {
 private:
  const char* msg_ =
      "The operation could not be processed because all continuation points "
      "have been allocated.";
  const uint32_t status = 0x804B0000;

 public:
  BadNoContinuationPoints() = default;
  virtual ~BadNoContinuationPoints() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadReferenceTypeIdInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The operation could not be processed because all continuation points "
      "have been allocated.";
  const uint32_t status = 0x804C0000;

 public:
  BadReferenceTypeIdInvalid() = default;
  virtual ~BadReferenceTypeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadBrowseDirectionInvalid : public BadStatusException {
 private:
  const char* msg_ = "The browse direction is not valid.";
  const uint32_t status = 0x804D0000;

 public:
  BadBrowseDirectionInvalid() = default;
  virtual ~BadBrowseDirectionInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeNotInView : public BadStatusException {
 private:
  const char* msg_ = "The node is not part of the view.";
  const uint32_t status = 0x804E0000;

 public:
  BadNodeNotInView() = default;
  virtual ~BadNodeNotInView() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServerUriInvalid : public BadStatusException {
 private:
  const char* msg_ = "The ServerUri is not a valid URI.";
  const uint32_t status = 0x804F0000;

 public:
  BadServerUriInvalid() = default;
  virtual ~BadServerUriInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServerNameMissing : public BadStatusException {
 private:
  const char* msg_ = "No ServerName was specified.";
  const uint32_t status = 0x80500000;

 public:
  BadServerNameMissing() = default;
  virtual ~BadServerNameMissing() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDiscoveryUrlMissing : public BadStatusException {
 private:
  const char* msg_ = "No DiscoveryUrl was specified.";
  const uint32_t status = 0x80510000;

 public:
  BadDiscoveryUrlMissing() = default;
  virtual ~BadDiscoveryUrlMissing() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSempahoreFileMissing : public BadStatusException {
 private:
  const char* msg_ = "The semaphore file specified by the client is not valid.";
  const uint32_t status = 0x80520000;

 public:
  BadSempahoreFileMissing() = default;
  virtual ~BadSempahoreFileMissing() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestTypeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The security token request type is not valid.";
  const uint32_t status = 0x80530000;

 public:
  BadRequestTypeInvalid() = default;
  virtual ~BadRequestTypeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecurityModeRejected : public BadStatusException {
 private:
  const char* msg_ =
      "The security mode does not meet the requirements set by the server.";
  const uint32_t status = 0x80540000;

 public:
  BadSecurityModeRejected() = default;
  virtual ~BadSecurityModeRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecurityPolicyRejected : public BadStatusException {
 private:
  const char* msg_ =
      "The security policy does not meet the requirements set by the server.";
  const uint32_t status = 0x80550000;

 public:
  BadSecurityPolicyRejected() = default;
  virtual ~BadSecurityPolicyRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManySessions : public BadStatusException {
 private:
  const char* msg_ = "The server has reached its maximum number of sessions.";
  const uint32_t status = 0x80560000;

 public:
  BadTooManySessions() = default;
  virtual ~BadTooManySessions() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadUserSignatureInvalid : public BadStatusException {
 private:
  const char* msg_ = "The user token signature is missing or invalid.";
  const uint32_t status = 0x80570000;

 public:
  BadUserSignatureInvalid() = default;
  virtual ~BadUserSignatureInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadApplicationSignatureInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The signature generated with the client certificate is missing or "
      "invalid.";
  const uint32_t status = 0x80580000;

 public:
  BadApplicationSignatureInvalid() = default;
  virtual ~BadApplicationSignatureInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoValidCertificates : public BadStatusException {
 private:
  const char* msg_ =
      "The client did not provide at least one software certificate that is "
      "valid and meets the profile requirements for the server.";
  const uint32_t status = 0x80590000;

 public:
  BadNoValidCertificates() = default;
  virtual ~BadNoValidCertificates() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadIdentityChangeNotSupported : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not support changing the user identity assigned to the "
      "session.";
  const uint32_t status = 0x80C60000;

 public:
  BadIdentityChangeNotSupported() = default;
  virtual ~BadIdentityChangeNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestCancelledByRequest : public BadStatusException {
 private:
  const char* msg_ =
      "The request was cancelled by the client with the Cancel service.";
  const uint32_t status = 0x805A0000;

 public:
  BadRequestCancelledByRequest() = default;
  virtual ~BadRequestCancelledByRequest() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadParentNodeIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The parent node id does not to refer to a valid node.";
  const uint32_t status = 0x805B0000;

 public:
  BadParentNodeIdInvalid() = default;
  virtual ~BadParentNodeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadReferenceNotAllowed : public BadStatusException {
 private:
  const char* msg_ =
      "The reference could not be created because it violates constraints "
      "imposed by the data model.";
  const uint32_t status = 0x805C0000;

 public:
  BadReferenceNotAllowed() = default;
  virtual ~BadReferenceNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeIdRejected : public BadStatusException {
 private:
  const char* msg_ =
      "The requested node id was reject because it was either invalid or "
      "server does not allow node ids to be specified by the client.";
  const uint32_t status = 0x805D0000;

 public:
  BadNodeIdRejected() = default;
  virtual ~BadNodeIdRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeIdExists : public BadStatusException {
 private:
  const char* msg_ = "The requested node id is already used by another node.";
  const uint32_t status = 0x805E0000;

 public:
  BadNodeIdExists() = default;
  virtual ~BadNodeIdExists() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeClassInvalid : public BadStatusException {
 private:
  const char* msg_ = "The node class is not valid.";
  const uint32_t status = 0x805F0000;

 public:
  BadNodeClassInvalid() = default;
  virtual ~BadNodeClassInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadBrowseNameInvalid : public BadStatusException {
 private:
  const char* msg_ = "The browse name is invalid.";
  const uint32_t status = 0x80600000;

 public:
  BadBrowseNameInvalid() = default;
  virtual ~BadBrowseNameInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadBrowseNameDuplicated : public BadStatusException {
 private:
  const char* msg_ =
      "The browse name is not unique among nodes that share the same "
      "relationship with the parent.";
  const uint32_t status = 0x80610000;

 public:
  BadBrowseNameDuplicated() = default;
  virtual ~BadBrowseNameDuplicated() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNodeAttributesInvalid : public BadStatusException {
 private:
  const char* msg_ = "The node attributes are not valid for the node class.";
  const uint32_t status = 0x80620000;

 public:
  BadNodeAttributesInvalid() = default;
  virtual ~BadNodeAttributesInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTypeDefinitionInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The type definition node id does not reference an appropriate type "
      "node.";
  const uint32_t status = 0x80630000;

 public:
  BadTypeDefinitionInvalid() = default;
  virtual ~BadTypeDefinitionInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSourceNodeIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The source node id does not reference a valid node.";
  const uint32_t status = 0x80640000;

 public:
  BadSourceNodeIdInvalid() = default;
  virtual ~BadSourceNodeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTargetNodeIdInvalid : public BadStatusException {
 private:
  const char* msg_ = "The target node id does not reference a valid node.";
  const uint32_t status = 0x80650000;

 public:
  BadTargetNodeIdInvalid() = default;
  virtual ~BadTargetNodeIdInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDuplicateReferenceNotAllowed : public BadStatusException {
 private:
  const char* msg_ = "The reference type between the nodes is already defined.";
  const uint32_t status = 0x80660000;

 public:
  BadDuplicateReferenceNotAllowed() = default;
  virtual ~BadDuplicateReferenceNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInvalidSelfReference : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not allow this type of self reference on this node.";
  const uint32_t status = 0x80670000;

 public:
  BadInvalidSelfReference() = default;
  virtual ~BadInvalidSelfReference() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadReferenceLocalOnly : public BadStatusException {
 private:
  const char* msg_ =
      "The reference type is not valid for a reference to a remote server.";
  const uint32_t status = 0x80680000;

 public:
  BadReferenceLocalOnly() = default;
  virtual ~BadReferenceLocalOnly() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoDeleteRights : public BadStatusException {
 private:
  const char* msg_ = "The server will not allow the node to be deleted.";
  const uint32_t status = 0x80690000;

 public:
  BadNoDeleteRights() = default;
  virtual ~BadNoDeleteRights() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainReferenceNotDeleted : public UncertainStatusException {
 private:
  const char* msg_ = "The server was not able to delete all target references.";
  const uint32_t status = 0x40BC0000;

 public:
  UncertainReferenceNotDeleted() = default;
  virtual ~UncertainReferenceNotDeleted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadServerIndexInvalid : public BadStatusException {
 private:
  const char* msg_ = "The server index is not valid.";
  const uint32_t status = 0x806A0000;

 public:
  BadServerIndexInvalid() = default;
  virtual ~BadServerIndexInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadViewIdUnknown : public BadStatusException {
 private:
  const char* msg_ = "The view id does not refer to a valid view node.";
  const uint32_t status = 0x806B0000;

 public:
  BadViewIdUnknown() = default;
  virtual ~BadViewIdUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadViewTimestampInvalid : public BadStatusException {
 private:
  const char* msg_ = "The view timestamp is not available or not supported.";
  const uint32_t status = 0x80C90000;

 public:
  BadViewTimestampInvalid() = default;
  virtual ~BadViewTimestampInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadViewParameterMismatch : public BadStatusException {
 private:
  const char* msg_ = "The view parameters are not consistent with each other.";
  const uint32_t status = 0x80CA0000;

 public:
  BadViewParameterMismatch() = default;
  virtual ~BadViewParameterMismatch() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadViewVersionInvalid : public BadStatusException {
 private:
  const char* msg_ = "The view version is not available or not supported.";
  const uint32_t status = 0x80CB0000;

 public:
  BadViewVersionInvalid() = default;
  virtual ~BadViewVersionInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainNotAllNodesAvailable : public UncertainStatusException {
 private:
  const char* msg_ =
      "The list of references may not be complete because the underlying "
      "system is not available.";
  const uint32_t status = 0x40C00000;

 public:
  UncertainNotAllNodesAvailable() = default;
  virtual ~UncertainNotAllNodesAvailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodResultsMayBeIncomplete : public GoodStatusException {
 private:
  const char* msg_ =
      "The server should have followed a reference to a node in a remote "
      "server but did not. The result set may be incomplete.";
  const uint32_t status = 0x00BA0000;

 public:
  GoodResultsMayBeIncomplete() = default;
  virtual ~GoodResultsMayBeIncomplete() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotTypeDefinition : public BadStatusException {
 private:
  const char* msg_ = "The provided Nodeid was not a type definition nodeid.";
  const uint32_t status = 0x80C80000;

 public:
  BadNotTypeDefinition() = default;
  virtual ~BadNotTypeDefinition() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainReferenceOutOfServer : public UncertainStatusException {
 private:
  const char* msg_ =
      "One of the references to follow in the relative path references to a "
      "node in the address space in another server.";
  const uint32_t status = 0x406C0000;

 public:
  UncertainReferenceOutOfServer() = default;
  virtual ~UncertainReferenceOutOfServer() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManyMatches : public BadStatusException {
 private:
  const char* msg_ = "The requested operation has too many matches to return.";
  const uint32_t status = 0x806D0000;

 public:
  BadTooManyMatches() = default;
  virtual ~BadTooManyMatches() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadQueryTooComplex : public BadStatusException {
 private:
  const char* msg_ =
      "The requested operation requires too many resources in the server.";
  const uint32_t status = 0x806E0000;

 public:
  BadQueryTooComplex() = default;
  virtual ~BadQueryTooComplex() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoMatch : public BadStatusException {
 private:
  const char* msg_ = "The requested operation has no match to return.";
  const uint32_t status = 0x806F0000;

 public:
  BadNoMatch() = default;
  virtual ~BadNoMatch() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMaxAgeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The max age parameter is invalid.";
  const uint32_t status = 0x80700000;

 public:
  BadMaxAgeInvalid() = default;
  virtual ~BadMaxAgeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecurityModeInsufficient : public BadStatusException {
 private:
  const char* msg_ =
      "The operation is not permitted over the current secure channel.";
  const uint32_t status = 0x80E60000;

 public:
  BadSecurityModeInsufficient() = default;
  virtual ~BadSecurityModeInsufficient() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadHistoryOperationInvalid : public BadStatusException {
 private:
  const char* msg_ = "The history details parameter is not valid.";
  const uint32_t status = 0x80710000;

 public:
  BadHistoryOperationInvalid() = default;
  virtual ~BadHistoryOperationInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadHistoryOperationUnsupported : public BadStatusException {
 private:
  const char* msg_ = "The server does not support the requested operation.";
  const uint32_t status = 0x80720000;

 public:
  BadHistoryOperationUnsupported() = default;
  virtual ~BadHistoryOperationUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInvalidTimestampArgument : public BadStatusException {
 private:
  const char* msg_ = "The defined timestamp to return was invalid.";
  const uint32_t status = 0x80BD0000;

 public:
  BadInvalidTimestampArgument() = default;
  virtual ~BadInvalidTimestampArgument() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadWriteNotSupported : public BadStatusException {
 private:
  const char* msg_ =
      "The server does not support writing the combination of value";
  const uint32_t status = 0x80730000;

 public:
  BadWriteNotSupported() = default;
  virtual ~BadWriteNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTypeMismatch : public BadStatusException {
 private:
  const char* msg_ =
      "The value supplied for the attribute is not of the same type as the "
      "attribute's value.";
  const uint32_t status = 0x80740000;

 public:
  BadTypeMismatch() = default;
  virtual ~BadTypeMismatch() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMethodInvalid : public BadStatusException {
 private:
  const char* msg_ =
      "The method id does not refer to a method for the specified object.";
  const uint32_t status = 0x80750000;

 public:
  BadMethodInvalid() = default;
  virtual ~BadMethodInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadArgumentsMissing : public BadStatusException {
 private:
  const char* msg_ =
      "The client did not specify all of the input arguments for the method.";
  const uint32_t status = 0x80760000;

 public:
  BadArgumentsMissing() = default;
  virtual ~BadArgumentsMissing() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManySubscriptions : public BadStatusException {
 private:
  const char* msg_ =
      "The server has reached its  maximum number of subscriptions.";
  const uint32_t status = 0x80770000;

 public:
  BadTooManySubscriptions() = default;
  virtual ~BadTooManySubscriptions() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTooManyPublishRequests : public BadStatusException {
 private:
  const char* msg_ =
      "The server has reached the maximum number of queued publish requests.";
  const uint32_t status = 0x80780000;

 public:
  BadTooManyPublishRequests() = default;
  virtual ~BadTooManyPublishRequests() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoSubscription : public BadStatusException {
 private:
  const char* msg_ = "There is no subscription available for this session.";
  const uint32_t status = 0x80790000;

 public:
  BadNoSubscription() = default;
  virtual ~BadNoSubscription() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSequenceNumberUnknown : public BadStatusException {
 private:
  const char* msg_ = "The sequence number is unknown to the server.";
  const uint32_t status = 0x807A0000;

 public:
  BadSequenceNumberUnknown() = default;
  virtual ~BadSequenceNumberUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMessageNotAvailable : public BadStatusException {
 private:
  const char* msg_ =
      "The requested notification message is no longer available.";
  const uint32_t status = 0x807B0000;

 public:
  BadMessageNotAvailable() = default;
  virtual ~BadMessageNotAvailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInsufficientClientProfile : public BadStatusException {
 private:
  const char* msg_ =
      "The client of the current session does not support one or more Profiles "
      "that are necessary for the subscription.";
  const uint32_t status = 0x807C0000;

 public:
  BadInsufficientClientProfile() = default;
  virtual ~BadInsufficientClientProfile() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadStateNotActive : public BadStatusException {
 private:
  const char* msg_ = "The sub-state machine is not currently active.";
  const uint32_t status = 0x80BF0000;

 public:
  BadStateNotActive() = default;
  virtual ~BadStateNotActive() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpServerTooBusy : public BadStatusException {
 private:
  const char* msg_ =
      "The server cannot process the request because it is too busy.";
  const uint32_t status = 0x807D0000;

 public:
  BadTcpServerTooBusy() = default;
  virtual ~BadTcpServerTooBusy() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpMessageTypeInvalid : public BadStatusException {
 private:
  const char* msg_ = "The type of the message specified in the header invalid.";
  const uint32_t status = 0x807E0000;

 public:
  BadTcpMessageTypeInvalid() = default;
  virtual ~BadTcpMessageTypeInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpSecureChannelUnknown : public BadStatusException {
 private:
  const char* msg_ =
      "The SecureChannelId and/or TokenId are not currently in use.";
  const uint32_t status = 0x807F0000;

 public:
  BadTcpSecureChannelUnknown() = default;
  virtual ~BadTcpSecureChannelUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpMessageTooLarge : public BadStatusException {
 private:
  const char* msg_ =
      "The size of the message specified in the header is too large.";
  const uint32_t status = 0x80800000;

 public:
  BadTcpMessageTooLarge() = default;
  virtual ~BadTcpMessageTooLarge() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpNotEnoughResources : public BadStatusException {
 private:
  const char* msg_ = "There are not enough resources to process the request.";
  const uint32_t status = 0x80810000;

 public:
  BadTcpNotEnoughResources() = default;
  virtual ~BadTcpNotEnoughResources() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpInternalError : public BadStatusException {
 private:
  const char* msg_ = "An internal error occurred.";
  const uint32_t status = 0x80820000;

 public:
  BadTcpInternalError() = default;
  virtual ~BadTcpInternalError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTcpEndpointUrlInvalid : public BadStatusException {
 private:
  const char* msg_ = "The server does not recognize the QueryString specified.";
  const uint32_t status = 0x80830000;

 public:
  BadTcpEndpointUrlInvalid() = default;
  virtual ~BadTcpEndpointUrlInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestInterrupted : public BadStatusException {
 private:
  const char* msg_ =
      "The request could not be sent because of a network interruption.";
  const uint32_t status = 0x80840000;

 public:
  BadRequestInterrupted() = default;
  virtual ~BadRequestInterrupted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestTimeout : public BadStatusException {
 private:
  const char* msg_ = "Timeout occurred while processing the request.";
  const uint32_t status = 0x80850000;

 public:
  BadRequestTimeout() = default;
  virtual ~BadRequestTimeout() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecureChannelClosed : public BadStatusException {
 private:
  const char* msg_ = "The secure channel has been closed.";
  const uint32_t status = 0x80860000;

 public:
  BadSecureChannelClosed() = default;
  virtual ~BadSecureChannelClosed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSecureChannelTokenUnknown : public BadStatusException {
 private:
  const char* msg_ = "The token has expired or is not recognized.";
  const uint32_t status = 0x80870000;

 public:
  BadSecureChannelTokenUnknown() = default;
  virtual ~BadSecureChannelTokenUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSequenceNumberInvalid : public BadStatusException {
 private:
  const char* msg_ = "The sequence number is not valid.";
  const uint32_t status = 0x80880000;

 public:
  BadSequenceNumberInvalid() = default;
  virtual ~BadSequenceNumberInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadProtocolVersionUnsupported : public BadStatusException {
 private:
  const char* msg_ =
      "The applications do not have compatible protocol versions.";
  const uint32_t status = 0x80BE0000;

 public:
  BadProtocolVersionUnsupported() = default;
  virtual ~BadProtocolVersionUnsupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConfigurationError : public BadStatusException {
 private:
  const char* msg_ =
      "There is a problem with the configuration that affects the usefulness "
      "of the value.";
  const uint32_t status = 0x80890000;

 public:
  BadConfigurationError() = default;
  virtual ~BadConfigurationError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNotConnected : public BadStatusException {
 private:
  const char* msg_ =
      "The variable should receive its value from another variable";
  const uint32_t status = 0x808A0000;

 public:
  BadNotConnected() = default;
  virtual ~BadNotConnected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDeviceFailure : public BadStatusException {
 private:
  const char* msg_ =
      "There has been a failure in the device/data source that generates the "
      "value that has affected the value.";
  const uint32_t status = 0x808B0000;

 public:
  BadDeviceFailure() = default;
  virtual ~BadDeviceFailure() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSensorFailure : public BadStatusException {
 private:
  const char* msg_ =
      "There has been a failure in the sensor from which the value is derived "
      "by the device/data source.";
  const uint32_t status = 0x808C0000;

 public:
  BadSensorFailure() = default;
  virtual ~BadSensorFailure() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadOutOfService : public BadStatusException {
 private:
  const char* msg_ = "The source of the data is not operational.";
  const uint32_t status = 0x808D0000;

 public:
  BadOutOfService() = default;
  virtual ~BadOutOfService() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDeadbandFilterInvalid : public BadStatusException {
 private:
  const char* msg_ = "The deadband filter is not valid.";
  const uint32_t status = 0x808E0000;

 public:
  BadDeadbandFilterInvalid() = default;
  virtual ~BadDeadbandFilterInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainNoCommunicationLastUsableValue
    : public UncertainStatusException {
 private:
  const char* msg_ =
      "Communication to the data source has failed. The variable value is the "
      "last value that had a good quality.";
  const uint32_t status = 0x408F0000;

 public:
  UncertainNoCommunicationLastUsableValue() = default;
  virtual ~UncertainNoCommunicationLastUsableValue() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainLastUsableValue : public UncertainStatusException {
 private:
  const char* msg_ = "Whatever was updating this value has stopped doing so.";
  const uint32_t status = 0x40900000;

 public:
  UncertainLastUsableValue() = default;
  virtual ~UncertainLastUsableValue() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainSubstituteValue : public UncertainStatusException {
 private:
  const char* msg_ =
      "The value is an operational value that was manually overwritten.";
  const uint32_t status = 0x40910000;

 public:
  UncertainSubstituteValue() = default;
  virtual ~UncertainSubstituteValue() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainInitialValue : public UncertainStatusException {
 private:
  const char* msg_ =
      "The value is an initial value for a variable that normally receives its "
      "value from another variable.";
  const uint32_t status = 0x40920000;

 public:
  UncertainInitialValue() = default;
  virtual ~UncertainInitialValue() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainSensorNotAccurate : public UncertainStatusException {
 private:
  const char* msg_ = "The value is at one of the sensor limits.";
  const uint32_t status = 0x40930000;

 public:
  UncertainSensorNotAccurate() = default;
  virtual ~UncertainSensorNotAccurate() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainEngineeringUnitsExceeded : public UncertainStatusException {
 private:
  const char* msg_ =
      "The value is outside of the range of values defined for this parameter.";
  const uint32_t status = 0x40940000;

 public:
  UncertainEngineeringUnitsExceeded() = default;
  virtual ~UncertainEngineeringUnitsExceeded() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainSubNormal : public UncertainStatusException {
 private:
  const char* msg_ =
      "The value is derived from multiple sources and has less than the "
      "required number of Good sources.";
  const uint32_t status = 0x40950000;

 public:
  UncertainSubNormal() = default;
  virtual ~UncertainSubNormal() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodLocalOverride : public GoodStatusException {
 private:
  const char* msg_ = "The value has been overridden.";
  const uint32_t status = 0x00960000;

 public:
  GoodLocalOverride() = default;
  virtual ~GoodLocalOverride() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRefreshInProgress : public BadStatusException {
 private:
  const char* msg_ = "This Condition refresh failed";
  const uint32_t status = 0x80970000;

 public:
  BadRefreshInProgress() = default;
  virtual ~BadRefreshInProgress() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionAlreadyDisabled : public BadStatusException {
 private:
  const char* msg_ = "This condition has already been disabled.";
  const uint32_t status = 0x80980000;

 public:
  BadConditionAlreadyDisabled() = default;
  virtual ~BadConditionAlreadyDisabled() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionAlreadyEnabled : public BadStatusException {
 private:
  const char* msg_ = "This condition has already been enabled.";
  const uint32_t status = 0x80CC0000;

 public:
  BadConditionAlreadyEnabled() = default;
  virtual ~BadConditionAlreadyEnabled() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionDisabled : public BadStatusException {
 private:
  const char* msg_ = "Property not available";
  const uint32_t status = 0x80990000;

 public:
  BadConditionDisabled() = default;
  virtual ~BadConditionDisabled() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEventIdUnknown : public BadStatusException {
 private:
  const char* msg_ = "The specified event id is not recognized.";
  const uint32_t status = 0x809A0000;

 public:
  BadEventIdUnknown() = default;
  virtual ~BadEventIdUnknown() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEventNotAcknowledgeable : public BadStatusException {
 private:
  const char* msg_ = "The event cannot be acknowledged.";
  const uint32_t status = 0x80BB0000;

 public:
  BadEventNotAcknowledgeable() = default;
  virtual ~BadEventNotAcknowledgeable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDialogNotActive : public BadStatusException {
 private:
  const char* msg_ = "The dialog condition is not active.";
  const uint32_t status = 0x80CD0000;

 public:
  BadDialogNotActive() = default;
  virtual ~BadDialogNotActive() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDialogResponseInvalid : public BadStatusException {
 private:
  const char* msg_ = "The response is not valid for the dialog.";
  const uint32_t status = 0x80CE0000;

 public:
  BadDialogResponseInvalid() = default;
  virtual ~BadDialogResponseInvalid() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionBranchAlreadyAcked : public BadStatusException {
 private:
  const char* msg_ = "The condition branch has already been acknowledged.";
  const uint32_t status = 0x80CF0000;

 public:
  BadConditionBranchAlreadyAcked() = default;
  virtual ~BadConditionBranchAlreadyAcked() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionBranchAlreadyConfirmed : public BadStatusException {
 private:
  const char* msg_ = "The condition branch has already been confirmed.";
  const uint32_t status = 0x80D00000;

 public:
  BadConditionBranchAlreadyConfirmed() = default;
  virtual ~BadConditionBranchAlreadyConfirmed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionAlreadyShelved : public BadStatusException {
 private:
  const char* msg_ = "The condition has already been shelved.";
  const uint32_t status = 0x80D10000;

 public:
  BadConditionAlreadyShelved() = default;
  virtual ~BadConditionAlreadyShelved() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConditionNotShelved : public BadStatusException {
 private:
  const char* msg_ = "The condition is not currently shelved.";
  const uint32_t status = 0x80D20000;

 public:
  BadConditionNotShelved() = default;
  virtual ~BadConditionNotShelved() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadShelvingTimeOutOfRange : public BadStatusException {
 private:
  const char* msg_ = "The shelving time not within an acceptable range.";
  const uint32_t status = 0x80D30000;

 public:
  BadShelvingTimeOutOfRange() = default;
  virtual ~BadShelvingTimeOutOfRange() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoData : public BadStatusException {
 private:
  const char* msg_ =
      "No data exists for the requested time range or event filter.";
  const uint32_t status = 0x809B0000;

 public:
  BadNoData() = default;
  virtual ~BadNoData() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadBoundNotFound : public BadStatusException {
 private:
  const char* msg_ = "No data found to provide upper or lower bound value.";
  const uint32_t status = 0x80D70000;

 public:
  BadBoundNotFound() = default;
  virtual ~BadBoundNotFound() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadBoundNotSupported : public BadStatusException {
 private:
  const char* msg_ = "The server cannot retrieve a bound for the variable.";
  const uint32_t status = 0x80D80000;

 public:
  BadBoundNotSupported() = default;
  virtual ~BadBoundNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDataLost : public BadStatusException {
 private:
  const char* msg_ = "Data is missing due to collection started/stopped/lost.";
  const uint32_t status = 0x809D0000;

 public:
  BadDataLost() = default;
  virtual ~BadDataLost() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDataUnavailable : public BadStatusException {
 private:
  const char* msg_ =
      "Expected data is unavailable for the requested time range due to an "
      "un-mounted volume";
  const uint32_t status = 0x809E0000;

 public:
  BadDataUnavailable() = default;
  virtual ~BadDataUnavailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEntryExists : public BadStatusException {
 private:
  const char* msg_ =
      "The data or event was not successfully inserted because a matching "
      "entry exists.";
  const uint32_t status = 0x809F0000;

 public:
  BadEntryExists() = default;
  virtual ~BadEntryExists() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoEntryExists : public BadStatusException {
 private:
  const char* msg_ =
      "The data or event was not successfully updated because no matching "
      "entry exists.";
  const uint32_t status = 0x80A00000;

 public:
  BadNoEntryExists() = default;
  virtual ~BadNoEntryExists() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadTimestampNotSupported : public BadStatusException {
 private:
  const char* msg_ =
      "The client requested history using a timestamp format the server does "
      "not support (i.e requested ServerTimestamp when server only supports "
      "SourceTimestamp).";
  const uint32_t status = 0x80A10000;

 public:
  BadTimestampNotSupported() = default;
  virtual ~BadTimestampNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodEntryInserted : public GoodStatusException {
 private:
  const char* msg_ =
      "The data or event was successfully inserted into the historical "
      "database.";
  const uint32_t status = 0x00A20000;

 public:
  GoodEntryInserted() = default;
  virtual ~GoodEntryInserted() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodEntryReplaced : public GoodStatusException {
 private:
  const char* msg_ =
      "The data or event field was successfully replaced in the historical "
      "database.";
  const uint32_t status = 0x00A30000;

 public:
  GoodEntryReplaced() = default;
  virtual ~GoodEntryReplaced() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainDataSubNormal : public UncertainStatusException {
 private:
  const char* msg_ =
      "The value is derived from multiple values and has less than the "
      "required number of Good values.";
  const uint32_t status = 0x40A40000;

 public:
  UncertainDataSubNormal() = default;
  virtual ~UncertainDataSubNormal() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodNoData : public GoodStatusException {
 private:
  const char* msg_ =
      "No data exists for the requested time range or event filter.";
  const uint32_t status = 0x00A50000;

 public:
  GoodNoData() = default;
  virtual ~GoodNoData() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodMoreData : public GoodStatusException {
 private:
  const char* msg_ =
      "The data or event field was successfully replaced in the historical "
      "database.";
  const uint32_t status = 0x00A60000;

 public:
  GoodMoreData() = default;
  virtual ~GoodMoreData() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadAggregateListMismatch : public BadStatusException {
 private:
  const char* msg_ =
      "The requested number of Aggregates does not match the requested number "
      "of NodeIds.";
  const uint32_t status = 0x80D40000;

 public:
  BadAggregateListMismatch() = default;
  virtual ~BadAggregateListMismatch() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadAggregateNotSupported : public BadStatusException {
 private:
  const char* msg_ = "The requested Aggregate is not support by the server.";
  const uint32_t status = 0x80D50000;

 public:
  BadAggregateNotSupported() = default;
  virtual ~BadAggregateNotSupported() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadAggregateInvalidInputs : public BadStatusException {
 private:
  const char* msg_ =
      "The aggregate value could not be derived due to invalid data inputs.";
  const uint32_t status = 0x80D60000;

 public:
  BadAggregateInvalidInputs() = default;
  virtual ~BadAggregateInvalidInputs() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadAggregateConfigurationRejected : public BadStatusException {
 private:
  const char* msg_ =
      "The aggregate configuration is not valid for specified node.";
  const uint32_t status = 0x80DA0000;

 public:
  BadAggregateConfigurationRejected() = default;
  virtual ~BadAggregateConfigurationRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodDataIgnored : public GoodStatusException {
 private:
  const char* msg_ =
      "The request pecifies fields which are not valid for the EventType or "
      "cannot be saved by the historian.";
  const uint32_t status = 0x00D90000;

 public:
  GoodDataIgnored() = default;
  virtual ~GoodDataIgnored() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadRequestNotAllowed : public BadStatusException {
 private:
  const char* msg_ =
      "The request was rejected by the server because it did not meet the "
      "criteria set by the server.";
  const uint32_t status = 0x80E40000;

 public:
  BadRequestNotAllowed() = default;
  virtual ~BadRequestNotAllowed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodEdited : public GoodStatusException {
 private:
  const char* msg_ =
      "The value does not come from the real source and has been edited by the "
      "server.";
  const uint32_t status = 0x00DC0000;

 public:
  GoodEdited() = default;
  virtual ~GoodEdited() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodPostActionFailed : public GoodStatusException {
 private:
  const char* msg_ = "There was an error in execution of these post-actions.";
  const uint32_t status = 0x00DD0000;

 public:
  GoodPostActionFailed() = default;
  virtual ~GoodPostActionFailed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainDominantValueChanged : public UncertainStatusException {
 private:
  const char* msg_ =
      "The related EngineeringUnit has been changed but the Variable Value is "
      "still provided based on the previous unit.";
  const uint32_t status = 0x40DE0000;

 public:
  UncertainDominantValueChanged() = default;
  virtual ~UncertainDominantValueChanged() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodDependentValueChanged : public GoodStatusException {
 private:
  const char* msg_ =
      "A dependent value has been changed but the change has not been applied "
      "to the device.";
  const uint32_t status = 0x00E00000;

 public:
  GoodDependentValueChanged() = default;
  virtual ~GoodDependentValueChanged() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDominantValueChanged : public BadStatusException {
 private:
  const char* msg_ =
      "The related EngineeringUnit has been changed but this change has not "
      "been applied to the device. The Variable Value is still dependent on "
      "the previous unit but its status is currently Bad.";
  const uint32_t status = 0x80E10000;

 public:
  BadDominantValueChanged() = default;
  virtual ~BadDominantValueChanged() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class UncertainDependentValueChanged : public UncertainStatusException {
 private:
  const char* msg_ =
      "A dependent value has been changed but the change has not been applied "
      "to the device. The quality of the dominant variable is uncertain.";
  const uint32_t status = 0x40E20000;

 public:
  UncertainDependentValueChanged() = default;
  virtual ~UncertainDependentValueChanged() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDependentValueChanged : public BadStatusException {
 private:
  const char* msg_ =
      "A dependent value has been changed but the change has not been applied "
      "to the device. The quality of the dominant variable is Bad.";
  const uint32_t status = 0x80E30000;

 public:
  BadDependentValueChanged() = default;
  virtual ~BadDependentValueChanged() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodCommunicationEvent : public GoodStatusException {
 private:
  const char* msg_ = "The communication layer has raised an event.";
  const uint32_t status = 0x00A70000;

 public:
  GoodCommunicationEvent() = default;
  virtual ~GoodCommunicationEvent() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodShutdownEvent : public GoodStatusException {
 private:
  const char* msg_ = "The system is shutting down.";
  const uint32_t status = 0x00A80000;

 public:
  GoodShutdownEvent() = default;
  virtual ~GoodShutdownEvent() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodCallAgain : public GoodStatusException {
 private:
  const char* msg_ =
      "The operation is not finished and needs to be called again.";
  const uint32_t status = 0x00A90000;

 public:
  GoodCallAgain() = default;
  virtual ~GoodCallAgain() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class GoodNonCriticalTimeout : public GoodStatusException {
 private:
  const char* msg_ = "A non-critical timeout occurred.";
  const uint32_t status = 0x00AA0000;

 public:
  GoodNonCriticalTimeout() = default;
  virtual ~GoodNonCriticalTimeout() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInvalidArgument : public BadStatusException {
 private:
  const char* msg_ = "One or more arguments are invalid.";
  const uint32_t status = 0x80AB0000;

 public:
  BadInvalidArgument() = default;
  virtual ~BadInvalidArgument() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConnectionRejected : public BadStatusException {
 private:
  const char* msg_ =
      "Could not establish a network connection to remote server.";
  const uint32_t status = 0x80AC0000;

 public:
  BadConnectionRejected() = default;
  virtual ~BadConnectionRejected() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadDisconnect : public BadStatusException {
 private:
  const char* msg_ = "The server has disconnected from the client.";
  const uint32_t status = 0x80AD0000;

 public:
  BadDisconnect() = default;
  virtual ~BadDisconnect() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadConnectionClosed : public BadStatusException {
 private:
  const char* msg_ = "The network connection has been closed.";
  const uint32_t status = 0x80AE0000;

 public:
  BadConnectionClosed() = default;
  virtual ~BadConnectionClosed() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadInvalidState : public BadStatusException {
 private:
  const char* msg_ =
      "The operation cannot be completed because the object is closed";
  const uint32_t status = 0x80AF0000;

 public:
  BadInvalidState() = default;
  virtual ~BadInvalidState() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadEndOfStream : public BadStatusException {
 private:
  const char* msg_ = "Cannot move beyond end of the stream.";
  const uint32_t status = 0x80B00000;

 public:
  BadEndOfStream() = default;
  virtual ~BadEndOfStream() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadNoDataAvailable : public BadStatusException {
 private:
  const char* msg_ =
      "No data is currently available for reading from a non-blocking stream.";
  const uint32_t status = 0x80B10000;

 public:
  BadNoDataAvailable() = default;
  virtual ~BadNoDataAvailable() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadWaitingForResponse : public BadStatusException {
 private:
  const char* msg_ = "The asynchronous operation is waiting for a response.";
  const uint32_t status = 0x80B20000;

 public:
  BadWaitingForResponse() = default;
  virtual ~BadWaitingForResponse() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadOperationAbandoned : public BadStatusException {
 private:
  const char* msg_ = "The asynchronous operation was abandoned by the caller.";
  const uint32_t status = 0x80B30000;

 public:
  BadOperationAbandoned() = default;
  virtual ~BadOperationAbandoned() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadExpectedStreamToBlock : public BadStatusException {
 private:
  const char* msg_ =
      "The stream did not return all data requested (possibly because it is a "
      "non-blocking stream).";
  const uint32_t status = 0x80B40000;

 public:
  BadExpectedStreamToBlock() = default;
  virtual ~BadExpectedStreamToBlock() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadWouldBlock : public BadStatusException {
 private:
  const char* msg_ =
      "Non blocking behaviour is required and the operation would block.";
  const uint32_t status = 0x80B50000;

 public:
  BadWouldBlock() = default;
  virtual ~BadWouldBlock() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadSyntaxError : public BadStatusException {
 private:
  const char* msg_ = "A value had an invalid syntax.";
  const uint32_t status = 0x80B60000;

 public:
  BadSyntaxError() = default;
  virtual ~BadSyntaxError() = default;

  virtual const char* what() const noexcept { return msg_; }
};

class BadMaxConnectionsReached : public BadStatusException {
 private:
  const char* msg_ =
      "The operation could not be finished because all available connections "
      "are in use.";
  const uint32_t status = 0x80B70000;

 public:
  BadMaxConnectionsReached() = default;
  virtual ~BadMaxConnectionsReached() = default;

  virtual const char* what() const noexcept { return msg_; }
};

const std::unordered_map<uint32_t, const char*> status_description_table = {
    {0x80010000, "An unexpected error occurred."},
    {0x80020000,
     "An internal error occurred as a result of a programming or configuration "
     "error."},
    {0x80030000, "Not enough memory to complete the operation."},
    {0x80040000, "An operating system resource is not available."},
    {0x80050000, "A low level communication error occurred."},
    {0x80060000,
     "Encoding halted because of invalid data in the objects being "
     "serialized."},
    {0x80070000, "Decoding halted because of invalid data in the stream."},
    {0x80080000,
     "The message encoding/decoding limits imposed by the stack have been "
     "exceeded."},
    {0x80B80000, "The request message size exceeds limits set by the server."},
    {0x80B90000, "The response message size exceeds limits set by the client."},
    {0x80090000, "An unrecognized response was received from the server."},
    {0x800A0000, "The operation timed out."},
    {0x800B0000, "The server does not support the requested service."},
    {0x800C0000,
     "The operation was cancelled because the application is shutting down."},
    {0x800D0000,
     "The operation could not complete because the client is not connected to "
     "the server."},
    {0x800E0000, "The server has stopped and cannot process any requests."},
    {0x800F0000,
     "There was nothing to do because the client passed a list of operations "
     "with no elements."},
    {0x80100000,
     "The request could not be processed because it specified too many "
     "operations."},
    {0x80DB0000,
     "The request could not be processed because there are too many monitored "
     "items in the subscription."},
    {0x80110000,
     "The extension object cannot be (de)serialized because the data type id "
     "is not recognized."},
    {0x80120000, "The certificate provided as a parameter is not valid."},
    {0x80130000, "An error occurred verifying security."},
    {0x80140000, "The certificate has expired or is not yet valid."},
    {0x80150000, "An issuer certificate has expired or is not yet valid."},
    {0x80160000,
     "The HostName used to connect to a server does not match a HostName in "
     "the certificate."},
    {0x80170000,
     "The URI specified in the ApplicationDescription does not match the URI "
     "in the certificate."},
    {0x80180000,
     "The certificate may not be used for the requested operation."},
    {0x80190000,
     "The issuer certificate may not be used for the requested operation."},
    {0x801A0000, "The certificate is not trusted."},
    {0x801B0000,
     "It was not possible to determine if the certificate has been revoked."},
    {0x801C0000,
     "It was not possible to determine if the issuer certificate has been "
     "revoked."},
    {0x801D0000, "The certificate has been revoked."},
    {0x801E0000, "The issuer certificate has been revoked."},
    {0x810D0000, "The certificate chain is incomplete."},
    {0x801F0000,
     "User does not have permission to perform the requested operation."},
    {0x80200000, "The user identity token is not valid."},
    {0x80210000,
     "The user identity token is valid but the server has rejected it."},
    {0x80220000, "The specified secure channel is no longer valid."},
    {0x80230000, "The timestamp is outside the range allowed by the server."},
    {0x80240000,
     "The nonce does appear to be not a random value or it is not the correct "
     "length."},
    {0x80250000, "The session id is not valid."},
    {0x80260000, "The session was closed by the client."},
    {0x80270000,
     "The session cannot be used because ActivateSession has not been called."},
    {0x80280000, "The subscription id is not valid."},
    {0x802A0000, "The header for the request is missing or invalid."},
    {0x802B0000, "The timestamps to return parameter is invalid."},
    {0x802C0000, "The request was cancelled by the client."},
    {0x80E50000, "Too many arguments were provided."},
    {0x810E0000,
     "The server requires a license to operate in general or to perform a "
     "service or operation"},
    {0x810F0000,
     "The server has limits on number of allowed operations / objects"},
    {0x81100000,
     "The server does not have a license which is required to operate in "
     "general or to perform a service or operation."},
    {0x002D0000, "The subscription was transferred to another session."},
    {0x002E0000, "The processing will complete asynchronously."},
    {0x002F0000, "Sampling has slowed down due to resource limitations."},
    {0x00300000, "The value written was accepted but was clamped."},
    {0x80310000, "Communication with the data source is defined"},
    {0x80320000,
     "Waiting for the server to obtain values from the underlying data "
     "source."},
    {0x80330000, "The syntax of the node id is not valid."},
    {0x80340000,
     "The node id refers to a node that does not exist in the server address "
     "space."},
    {0x80350000, "The attribute is not supported for the specified Node."},
    {0x80360000, "The syntax of the index range parameter is invalid."},
    {0x80370000, "No data exists within the range of indexes specified."},
    {0x80380000, "The data encoding is invalid."},
    {0x80390000,
     "The server does not support the requested data encoding for the node."},
    {0x803A0000,
     "The access level does not allow reading or subscribing to the Node."},
    {0x803B0000, "The access level does not allow writing to the Node."},
    {0x803C0000, "The value was out of range."},
    {0x803D0000, "The requested operation is not supported."},
    {0x803E0000,
     "A requested item was not found or a search operation ended without "
     "success."},
    {0x803F0000, "The object cannot be used because it has been deleted."},
    {0x80400000, "Requested operation is not implemented."},
    {0x80410000, "The monitoring mode is invalid."},
    {0x80420000,
     "The monitoring item id does not refer to a valid monitored item."},
    {0x80430000, "The monitored item filter parameter is not valid."},
    {0x80440000,
     "The server does not support the requested monitored item filter."},
    {0x80450000,
     "A monitoring filter cannot be used in combination with the attribute "
     "specified."},
    {0x80460000, "A mandatory structured parameter was missing or null."},
    {0x80470000, "The event filter is not valid."},
    {0x80480000, "The content filter is not valid."},
    {0x80C10000, "An unregognized operator was provided in a filter."},
    {0x80C20000, "A valid operator was provided"},
    {0x80C30000,
     "The number of operands provided for the filter operator was less then "
     "expected for the operand provided."},
    {0x80490000, "The operand used in a content filter is not valid."},
    {0x80C40000,
     "The referenced element is not a valid element in the content filter."},
    {0x80C50000, "The referenced literal is not a valid value."},
    {0x804A0000, "The continuation point provide is longer valid."},
    {0x804B0000,
     "The operation could not be processed because all continuation points "
     "have been allocated."},
    {0x804C0000,
     "The operation could not be processed because all continuation points "
     "have been allocated."},
    {0x804D0000, "The browse direction is not valid."},
    {0x804E0000, "The node is not part of the view."},
    {0x804F0000, "The ServerUri is not a valid URI."},
    {0x80500000, "No ServerName was specified."},
    {0x80510000, "No DiscoveryUrl was specified."},
    {0x80520000, "The semaphore file specified by the client is not valid."},
    {0x80530000, "The security token request type is not valid."},
    {0x80540000,
     "The security mode does not meet the requirements set by the server."},
    {0x80550000,
     "The security policy does not meet the requirements set by the server."},
    {0x80560000, "The server has reached its maximum number of sessions."},
    {0x80570000, "The user token signature is missing or invalid."},
    {0x80580000,
     "The signature generated with the client certificate is missing or "
     "invalid."},
    {0x80590000,
     "The client did not provide at least one software certificate that is "
     "valid and meets the profile requirements for the server."},
    {0x80C60000,
     "The server does not support changing the user identity assigned to the "
     "session."},
    {0x805A0000,
     "The request was cancelled by the client with the Cancel service."},
    {0x805B0000, "The parent node id does not to refer to a valid node."},
    {0x805C0000,
     "The reference could not be created because it violates constraints "
     "imposed by the data model."},
    {0x805D0000,
     "The requested node id was reject because it was either invalid or server "
     "does not allow node ids to be specified by the client."},
    {0x805E0000, "The requested node id is already used by another node."},
    {0x805F0000, "The node class is not valid."},
    {0x80600000, "The browse name is invalid."},
    {0x80610000,
     "The browse name is not unique among nodes that share the same "
     "relationship with the parent."},
    {0x80620000, "The node attributes are not valid for the node class."},
    {0x80630000,
     "The type definition node id does not reference an appropriate type "
     "node."},
    {0x80640000, "The source node id does not reference a valid node."},
    {0x80650000, "The target node id does not reference a valid node."},
    {0x80660000, "The reference type between the nodes is already defined."},
    {0x80670000,
     "The server does not allow this type of self reference on this node."},
    {0x80680000,
     "The reference type is not valid for a reference to a remote server."},
    {0x80690000, "The server will not allow the node to be deleted."},
    {0x40BC0000, "The server was not able to delete all target references."},
    {0x806A0000, "The server index is not valid."},
    {0x806B0000, "The view id does not refer to a valid view node."},
    {0x80C90000, "The view timestamp is not available or not supported."},
    {0x80CA0000, "The view parameters are not consistent with each other."},
    {0x80CB0000, "The view version is not available or not supported."},
    {0x40C00000,
     "The list of references may not be complete because the underlying system "
     "is not available."},
    {0x00BA0000,
     "The server should have followed a reference to a node in a remote server "
     "but did not. The result set may be incomplete."},
    {0x80C80000, "The provided Nodeid was not a type definition nodeid."},
    {0x406C0000,
     "One of the references to follow in the relative path references to a "
     "node in the address space in another server."},
    {0x806D0000, "The requested operation has too many matches to return."},
    {0x806E0000,
     "The requested operation requires too many resources in the server."},
    {0x806F0000, "The requested operation has no match to return."},
    {0x80700000, "The max age parameter is invalid."},
    {0x80E60000,
     "The operation is not permitted over the current secure channel."},
    {0x80710000, "The history details parameter is not valid."},
    {0x80720000, "The server does not support the requested operation."},
    {0x80BD0000, "The defined timestamp to return was invalid."},
    {0x80730000,
     "The server does not support writing the combination of value"},
    {0x80740000,
     "The value supplied for the attribute is not of the same type as the "
     "attribute's value."},
    {0x80750000,
     "The method id does not refer to a method for the specified object."},
    {0x80760000,
     "The client did not specify all of the input arguments for the method."},
    {0x80770000,
     "The server has reached its  maximum number of subscriptions."},
    {0x80780000,
     "The server has reached the maximum number of queued publish requests."},
    {0x80790000, "There is no subscription available for this session."},
    {0x807A0000, "The sequence number is unknown to the server."},
    {0x807B0000, "The requested notification message is no longer available."},
    {0x807C0000,
     "The client of the current session does not support one or more Profiles "
     "that are necessary for the subscription."},
    {0x80BF0000, "The sub-state machine is not currently active."},
    {0x807D0000,
     "The server cannot process the request because it is too busy."},
    {0x807E0000, "The type of the message specified in the header invalid."},
    {0x807F0000,
     "The SecureChannelId and/or TokenId are not currently in use."},
    {0x80800000,
     "The size of the message specified in the header is too large."},
    {0x80810000, "There are not enough resources to process the request."},
    {0x80820000, "An internal error occurred."},
    {0x80830000, "The server does not recognize the QueryString specified."},
    {0x80840000,
     "The request could not be sent because of a network interruption."},
    {0x80850000, "Timeout occurred while processing the request."},
    {0x80860000, "The secure channel has been closed."},
    {0x80870000, "The token has expired or is not recognized."},
    {0x80880000, "The sequence number is not valid."},
    {0x80BE0000, "The applications do not have compatible protocol versions."},
    {0x80890000,
     "There is a problem with the configuration that affects the usefulness of "
     "the value."},
    {0x808A0000, "The variable should receive its value from another variable"},
    {0x808B0000,
     "There has been a failure in the device/data source that generates the "
     "value that has affected the value."},
    {0x808C0000,
     "There has been a failure in the sensor from which the value is derived "
     "by the device/data source."},
    {0x808D0000, "The source of the data is not operational."},
    {0x808E0000, "The deadband filter is not valid."},
    {0x408F0000,
     "Communication to the data source has failed. The variable value is the "
     "last value that had a good quality."},
    {0x40900000, "Whatever was updating this value has stopped doing so."},
    {0x40910000,
     "The value is an operational value that was manually overwritten."},
    {0x40920000,
     "The value is an initial value for a variable that normally receives its "
     "value from another variable."},
    {0x40930000, "The value is at one of the sensor limits."},
    {0x40940000,
     "The value is outside of the range of values defined for this parameter."},
    {0x40950000,
     "The value is derived from multiple sources and has less than the "
     "required number of Good sources."},
    {0x00960000, "The value has been overridden."},
    {0x80970000, "This Condition refresh failed"},
    {0x80980000, "This condition has already been disabled."},
    {0x80CC0000, "This condition has already been enabled."},
    {0x80990000, "Property not available"},
    {0x809A0000, "The specified event id is not recognized."},
    {0x80BB0000, "The event cannot be acknowledged."},
    {0x80CD0000, "The dialog condition is not active."},
    {0x80CE0000, "The response is not valid for the dialog."},
    {0x80CF0000, "The condition branch has already been acknowledged."},
    {0x80D00000, "The condition branch has already been confirmed."},
    {0x80D10000, "The condition has already been shelved."},
    {0x80D20000, "The condition is not currently shelved."},
    {0x80D30000, "The shelving time not within an acceptable range."},
    {0x809B0000,
     "No data exists for the requested time range or event filter."},
    {0x80D70000, "No data found to provide upper or lower bound value."},
    {0x80D80000, "The server cannot retrieve a bound for the variable."},
    {0x809D0000, "Data is missing due to collection started/stopped/lost."},
    {0x809E0000,
     "Expected data is unavailable for the requested time range due to an "
     "un-mounted volume"},
    {0x809F0000,
     "The data or event was not successfully inserted because a matching entry "
     "exists."},
    {0x80A00000,
     "The data or event was not successfully updated because no matching entry "
     "exists."},
    {0x80A10000,
     "The client requested history using a timestamp format the server does "
     "not support (i.e requested ServerTimestamp when server only supports "
     "SourceTimestamp)."},
    {0x00A20000,
     "The data or event was successfully inserted into the historical "
     "database."},
    {0x00A30000,
     "The data or event field was successfully replaced in the historical "
     "database."},
    {0x40A40000,
     "The value is derived from multiple values and has less than the required "
     "number of Good values."},
    {0x00A50000,
     "No data exists for the requested time range or event filter."},
    {0x00A60000,
     "The data or event field was successfully replaced in the historical "
     "database."},
    {0x80D40000,
     "The requested number of Aggregates does not match the requested number "
     "of NodeIds."},
    {0x80D50000, "The requested Aggregate is not support by the server."},
    {0x80D60000,
     "The aggregate value could not be derived due to invalid data inputs."},
    {0x80DA0000,
     "The aggregate configuration is not valid for specified node."},
    {0x00D90000,
     "The request pecifies fields which are not valid for the EventType or "
     "cannot be saved by the historian."},
    {0x80E40000,
     "The request was rejected by the server because it did not meet the "
     "criteria set by the server."},
    {0x00DC0000,
     "The value does not come from the real source and has been edited by the "
     "server."},
    {0x00DD0000, "There was an error in execution of these post-actions."},
    {0x40DE0000,
     "The related EngineeringUnit has been changed but the Variable Value is "
     "still provided based on the previous unit."},
    {0x00E00000,
     "A dependent value has been changed but the change has not been applied "
     "to the device."},
    {0x80E10000,
     "The related EngineeringUnit has been changed but this change has not "
     "been applied to the device. The Variable Value is still dependent on the "
     "previous unit but its status is currently Bad."},
    {0x40E20000,
     "A dependent value has been changed but the change has not been applied "
     "to the device. The quality of the dominant variable is uncertain."},
    {0x80E30000,
     "A dependent value has been changed but the change has not been applied "
     "to the device. The quality of the dominant variable is Bad."},
    {0x00A70000, "The communication layer has raised an event."},
    {0x00A80000, "The system is shutting down."},
    {0x00A90000, "The operation is not finished and needs to be called again."},
    {0x00AA0000, "A non-critical timeout occurred."},
    {0x80AB0000, "One or more arguments are invalid."},
    {0x80AC0000, "Could not establish a network connection to remote server."},
    {0x80AD0000, "The server has disconnected from the client."},
    {0x80AE0000, "The network connection has been closed."},
    {0x80AF0000,
     "The operation cannot be completed because the object is closed"},
    {0x80B00000, "Cannot move beyond end of the stream."},
    {0x80B10000,
     "No data is currently available for reading from a non-blocking stream."},
    {0x80B20000, "The asynchronous operation is waiting for a response."},
    {0x80B30000, "The asynchronous operation was abandoned by the caller."},
    {0x80B40000,
     "The stream did not return all data requested (possibly because it is a "
     "non-blocking stream)."},
    {0x80B50000,
     "Non blocking behaviour is required and the operation would block."},
    {0x80B60000, "A value had an invalid syntax."},
    {0x80B70000,
     "The operation could not be finished because all available connections "
     "are in use."}};

void throw_from_status(uint32_t status_code);
const char* get_status_description_string(uint32_t status_code);

}  // namespace diag
}  // namespace opcua

#endif  //