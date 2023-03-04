#include <gtest/gtest.h>

#include <open62541cpp/common/exception/exceptions_extended.hpp>
#include <open62541cpp/net/client/client.hpp>

namespace opcua::diag::test {

class OpcuaExceptionTest : public ::testing::Test {};

TEST_F(OpcuaExceptionTest, BadUnexpectedErrorTest) {
  try {
    throw_from_status(0x80010000);
    EXPECT_TRUE(false);
  } catch (const BadUnexpectedError& e) {
    std::string message{"An unexpected error occurred."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInternalErrorTest) {
  try {
    throw_from_status(0x80020000);
    EXPECT_TRUE(false);
  } catch (const BadInternalError& e) {
    std::string message{
        "An internal error occurred as a result of a programming or "
        "configuration error."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadOutOfMemoryTest) {
  try {
    throw_from_status(0x80030000);
    EXPECT_TRUE(false);
  } catch (const BadOutOfMemory& e) {
    std::string message{"Not enough memory to complete the operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadResourceUnavailableTest) {
  try {
    throw_from_status(0x80040000);
    EXPECT_TRUE(false);
  } catch (const BadResourceUnavailable& e) {
    std::string message{"An operating system resource is not available."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCommunicationErrorTest) {
  try {
    throw_from_status(0x80050000);
    EXPECT_TRUE(false);
  } catch (const BadCommunicationError& e) {
    std::string message{"A low level communication error occurred."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEncodingErrorTest) {
  try {
    throw_from_status(0x80060000);
    EXPECT_TRUE(false);
  } catch (const BadEncodingError& e) {
    std::string message{
        "Encoding halted because of invalid data in the objects being "
        "serialized."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDecodingErrorTest) {
  try {
    throw_from_status(0x80070000);
    EXPECT_TRUE(false);
  } catch (const BadDecodingError& e) {
    std::string message{
        "Decoding halted because of invalid data in the stream."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEncodingLimitsExceededTest) {
  try {
    throw_from_status(0x80080000);
    EXPECT_TRUE(false);
  } catch (const BadEncodingLimitsExceeded& e) {
    std::string message{
        "The message encoding/decoding limits imposed by the stack have been "
        "exceeded."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestTooLargeTest) {
  try {
    throw_from_status(0x80B80000);
    EXPECT_TRUE(false);
  } catch (const BadRequestTooLarge& e) {
    std::string message{
        "The request message size exceeds limits set by the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadResponseTooLargeTest) {
  try {
    throw_from_status(0x80B90000);
    EXPECT_TRUE(false);
  } catch (const BadResponseTooLarge& e) {
    std::string message{
        "The response message size exceeds limits set by the client."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadUnknownResponseTest) {
  try {
    throw_from_status(0x80090000);
    EXPECT_TRUE(false);
  } catch (const BadUnknownResponse& e) {
    std::string message{
        "An unrecognized response was received from the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTimeoutTest) {
  try {
    throw_from_status(0x800A0000);
    EXPECT_TRUE(false);
  } catch (const BadTimeout& e) {
    std::string message{"The operation timed out."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServiceUnsupportedTest) {
  try {
    throw_from_status(0x800B0000);
    EXPECT_TRUE(false);
  } catch (const BadServiceUnsupported& e) {
    std::string message{"The server does not support the requested service."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadShutdownTest) {
  try {
    throw_from_status(0x800C0000);
    EXPECT_TRUE(false);
  } catch (const BadShutdown& e) {
    std::string message{
        "The operation was cancelled because the application is shutting "
        "down."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServerNotConnectedTest) {
  try {
    throw_from_status(0x800D0000);
    EXPECT_TRUE(false);
  } catch (const BadServerNotConnected& e) {
    std::string message{
        "The operation could not complete because the client is not connected "
        "to the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServerHaltedTest) {
  try {
    throw_from_status(0x800E0000);
    EXPECT_TRUE(false);
  } catch (const BadServerHalted& e) {
    std::string message{
        "The server has stopped and cannot process any requests."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNothingToDoTest) {
  try {
    throw_from_status(0x800F0000);
    EXPECT_TRUE(false);
  } catch (const BadNothingToDo& e) {
    std::string message{
        "There was nothing to do because the client passed a list of "
        "operations with no elements."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManyOperationsTest) {
  try {
    throw_from_status(0x80100000);
    EXPECT_TRUE(false);
  } catch (const BadTooManyOperations& e) {
    std::string message{
        "The request could not be processed because it specified too many "
        "operations."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManyMonitoredItemsTest) {
  try {
    throw_from_status(0x80DB0000);
    EXPECT_TRUE(false);
  } catch (const BadTooManyMonitoredItems& e) {
    std::string message{
        "The request could not be processed because there are too many "
        "monitored items in the subscription."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDataTypeIdUnknownTest) {
  try {
    throw_from_status(0x80110000);
    EXPECT_TRUE(false);
  } catch (const BadDataTypeIdUnknown& e) {
    std::string message{
        "The extension object cannot be (de)serialized because the data type "
        "id is not recognized."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateInvalidTest) {
  try {
    throw_from_status(0x80120000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateInvalid& e) {
    std::string message{
        "The certificate provided as a parameter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecurityChecksFailedTest) {
  try {
    throw_from_status(0x80130000);
    EXPECT_TRUE(false);
  } catch (const BadSecurityChecksFailed& e) {
    std::string message{"An error occurred verifying security."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateTimeInvalidTest) {
  try {
    throw_from_status(0x80140000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateTimeInvalid& e) {
    std::string message{"The certificate has expired or is not yet valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateIssuerTimeInvalidTest) {
  try {
    throw_from_status(0x80150000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateIssuerTimeInvalid& e) {
    std::string message{
        "An issuer certificate has expired or is not yet valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateHostNameInvalidTest) {
  try {
    throw_from_status(0x80160000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateHostNameInvalid& e) {
    std::string message{
        "The HostName used to connect to a server does not match a HostName in "
        "the certificate."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateUriInvalidTest) {
  try {
    throw_from_status(0x80170000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateUriInvalid& e) {
    std::string message{
        "The URI specified in the ApplicationDescription does not match the "
        "URI in the certificate."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateUseNotAllowedTest) {
  try {
    throw_from_status(0x80180000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateUseNotAllowed& e) {
    std::string message{
        "The certificate may not be used for the requested operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateIssuerUseNotAllowedTest) {
  try {
    throw_from_status(0x80190000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateIssuerUseNotAllowed& e) {
    std::string message{
        "The issuer certificate may not be used for the requested operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateUntrustedTest) {
  try {
    throw_from_status(0x801A0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateUntrusted& e) {
    std::string message{"The certificate is not trusted."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateRevocationUnknownTest) {
  try {
    throw_from_status(0x801B0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateRevocationUnknown& e) {
    std::string message{
        "It was not possible to determine if the certificate has been "
        "revoked."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateIssuerRevocationUnknownTest) {
  try {
    throw_from_status(0x801C0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateIssuerRevocationUnknown& e) {
    std::string message{
        "It was not possible to determine if the issuer certificate has been "
        "revoked."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateRevokedTest) {
  try {
    throw_from_status(0x801D0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateRevoked& e) {
    std::string message{"The certificate has been revoked."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateIssuerRevokedTest) {
  try {
    throw_from_status(0x801E0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateIssuerRevoked& e) {
    std::string message{"The issuer certificate has been revoked."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadCertificateChainIncompleteTest) {
  try {
    throw_from_status(0x810D0000);
    EXPECT_TRUE(false);
  } catch (const BadCertificateChainIncomplete& e) {
    std::string message{"The certificate chain is incomplete."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadUserAccessDeniedTest) {
  try {
    throw_from_status(0x801F0000);
    EXPECT_TRUE(false);
  } catch (const BadUserAccessDenied& e) {
    std::string message{
        "User does not have permission to perform the requested operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadIdentityTokenInvalidTest) {
  try {
    throw_from_status(0x80200000);
    EXPECT_TRUE(false);
  } catch (const BadIdentityTokenInvalid& e) {
    std::string message{"The user identity token is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadIdentityTokenRejectedTest) {
  try {
    throw_from_status(0x80210000);
    EXPECT_TRUE(false);
  } catch (const BadIdentityTokenRejected& e) {
    std::string message{
        "The user identity token is valid but the server has rejected it."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecureChannelIdInvalidTest) {
  try {
    throw_from_status(0x80220000);
    EXPECT_TRUE(false);
  } catch (const BadSecureChannelIdInvalid& e) {
    std::string message{"The specified secure channel is no longer valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInvalidTimestampTest) {
  try {
    throw_from_status(0x80230000);
    EXPECT_TRUE(false);
  } catch (const BadInvalidTimestamp& e) {
    std::string message{
        "The timestamp is outside the range allowed by the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNonceInvalidTest) {
  try {
    throw_from_status(0x80240000);
    EXPECT_TRUE(false);
  } catch (const BadNonceInvalid& e) {
    std::string message{
        "The nonce does appear to be not a random value or it is not the "
        "correct length."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSessionIdInvalidTest) {
  try {
    throw_from_status(0x80250000);
    EXPECT_TRUE(false);
  } catch (const BadSessionIdInvalid& e) {
    std::string message{"The session id is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSessionClosedTest) {
  try {
    throw_from_status(0x80260000);
    EXPECT_TRUE(false);
  } catch (const BadSessionClosed& e) {
    std::string message{"The session was closed by the client."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSessionNotActivatedTest) {
  try {
    throw_from_status(0x80270000);
    EXPECT_TRUE(false);
  } catch (const BadSessionNotActivated& e) {
    std::string message{
        "The session cannot be used because ActivateSession has not been "
        "called."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSubscriptionIdInvalidTest) {
  try {
    throw_from_status(0x80280000);
    EXPECT_TRUE(false);
  } catch (const BadSubscriptionIdInvalid& e) {
    std::string message{"The subscription id is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestHeaderInvalidTest) {
  try {
    throw_from_status(0x802A0000);
    EXPECT_TRUE(false);
  } catch (const BadRequestHeaderInvalid& e) {
    std::string message{"The header for the request is missing or invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTimestampsToReturnInvalidTest) {
  try {
    throw_from_status(0x802B0000);
    EXPECT_TRUE(false);
  } catch (const BadTimestampsToReturnInvalid& e) {
    std::string message{"The timestamps to return parameter is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestCancelledByClientTest) {
  try {
    throw_from_status(0x802C0000);
    EXPECT_TRUE(false);
  } catch (const BadRequestCancelledByClient& e) {
    std::string message{"The request was cancelled by the client."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManyArgumentsTest) {
  try {
    throw_from_status(0x80E50000);
    EXPECT_TRUE(false);
  } catch (const BadTooManyArguments& e) {
    std::string message{"Too many arguments were provided."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadLicenseExpiredTest) {
  try {
    throw_from_status(0x810E0000);
    EXPECT_TRUE(false);
  } catch (const BadLicenseExpired& e) {
    std::string message{
        "The server requires a license to operate in general or to perform a "
        "service or operation"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadLicenseLimitsExceededTest) {
  try {
    throw_from_status(0x810F0000);
    EXPECT_TRUE(false);
  } catch (const BadLicenseLimitsExceeded& e) {
    std::string message{
        "The server has limits on number of allowed operations / objects"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadLicenseNotAvailableTest) {
  try {
    throw_from_status(0x81100000);
    EXPECT_TRUE(false);
  } catch (const BadLicenseNotAvailable& e) {
    std::string message{
        "The server does not have a license which is required to operate in "
        "general or to perform a service or operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodSubscriptionTransferredTest) {
  try {
    throw_from_status(0x002D0000);
    EXPECT_TRUE(false);
  } catch (const GoodSubscriptionTransferred& e) {
    std::string message{"The subscription was transferred to another session."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodCompletesAsynchronouslyTest) {
  try {
    throw_from_status(0x002E0000);
    EXPECT_TRUE(false);
  } catch (const GoodCompletesAsynchronously& e) {
    std::string message{"The processing will complete asynchronously."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodOverloadTest) {
  try {
    throw_from_status(0x002F0000);
    EXPECT_TRUE(false);
  } catch (const GoodOverload& e) {
    std::string message{
        "Sampling has slowed down due to resource limitations."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodClampedTest) {
  try {
    throw_from_status(0x00300000);
    EXPECT_TRUE(false);
  } catch (const GoodClamped& e) {
    std::string message{"The value written was accepted but was clamped."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoCommunicationTest) {
  try {
    throw_from_status(0x80310000);
    EXPECT_TRUE(false);
  } catch (const BadNoCommunication& e) {
    std::string message{"Communication with the data source is defined"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadWaitingForInitialDataTest) {
  try {
    throw_from_status(0x80320000);
    EXPECT_TRUE(false);
  } catch (const BadWaitingForInitialData& e) {
    std::string message{
        "Waiting for the server to obtain values from the underlying data "
        "source."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeIdInvalidTest) {
  try {
    throw_from_status(0x80330000);
    EXPECT_TRUE(false);
  } catch (const BadNodeIdInvalid& e) {
    std::string message{"The syntax of the node id is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeIdUnknownTest) {
  try {
    throw_from_status(0x80340000);
    EXPECT_TRUE(false);
  } catch (const BadNodeIdUnknown& e) {
    std::string message{
        "The node id refers to a node that does not exist in the server "
        "address space."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadAttributeIdInvalidTest) {
  try {
    throw_from_status(0x80350000);
    EXPECT_TRUE(false);
  } catch (const BadAttributeIdInvalid& e) {
    std::string message{
        "The attribute is not supported for the specified Node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadIndexRangeInvalidTest) {
  try {
    throw_from_status(0x80360000);
    EXPECT_TRUE(false);
  } catch (const BadIndexRangeInvalid& e) {
    std::string message{"The syntax of the index range parameter is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadIndexRangeNoDataTest) {
  try {
    throw_from_status(0x80370000);
    EXPECT_TRUE(false);
  } catch (const BadIndexRangeNoData& e) {
    std::string message{
        "No data exists within the range of indexes specified."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDataEncodingInvalidTest) {
  try {
    throw_from_status(0x80380000);
    EXPECT_TRUE(false);
  } catch (const BadDataEncodingInvalid& e) {
    std::string message{"The data encoding is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDataEncodingUnsupportedTest) {
  try {
    throw_from_status(0x80390000);
    EXPECT_TRUE(false);
  } catch (const BadDataEncodingUnsupported& e) {
    std::string message{
        "The server does not support the requested data encoding for the "
        "node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotReadableTest) {
  try {
    throw_from_status(0x803A0000);
    EXPECT_TRUE(false);
  } catch (const BadNotReadable& e) {
    std::string message{
        "The access level does not allow reading or subscribing to the Node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotWritableTest) {
  try {
    throw_from_status(0x803B0000);
    EXPECT_TRUE(false);
  } catch (const BadNotWritable& e) {
    std::string message{"The access level does not allow writing to the Node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadOutOfRangeTest) {
  try {
    throw_from_status(0x803C0000);
    EXPECT_TRUE(false);
  } catch (const BadOutOfRange& e) {
    std::string message{"The value was out of range."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotSupportedTest) {
  try {
    throw_from_status(0x803D0000);
    EXPECT_TRUE(false);
  } catch (const BadNotSupported& e) {
    std::string message{"The requested operation is not supported."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotFoundTest) {
  try {
    throw_from_status(0x803E0000);
    EXPECT_TRUE(false);
  } catch (const BadNotFound& e) {
    std::string message{
        "A requested item was not found or a search operation ended without "
        "success."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadObjectDeletedTest) {
  try {
    throw_from_status(0x803F0000);
    EXPECT_TRUE(false);
  } catch (const BadObjectDeleted& e) {
    std::string message{
        "The object cannot be used because it has been deleted."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotImplementedTest) {
  try {
    throw_from_status(0x80400000);
    EXPECT_TRUE(false);
  } catch (const BadNotImplemented& e) {
    std::string message{"Requested operation is not implemented."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMonitoringModeInvalidTest) {
  try {
    throw_from_status(0x80410000);
    EXPECT_TRUE(false);
  } catch (const BadMonitoringModeInvalid& e) {
    std::string message{"The monitoring mode is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMonitoredItemIdInvalidTest) {
  try {
    throw_from_status(0x80420000);
    EXPECT_TRUE(false);
  } catch (const BadMonitoredItemIdInvalid& e) {
    std::string message{
        "The monitoring item id does not refer to a valid monitored item."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMonitoredItemFilterInvalidTest) {
  try {
    throw_from_status(0x80430000);
    EXPECT_TRUE(false);
  } catch (const BadMonitoredItemFilterInvalid& e) {
    std::string message{"The monitored item filter parameter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMonitoredItemFilterUnsupportedTest) {
  try {
    throw_from_status(0x80440000);
    EXPECT_TRUE(false);
  } catch (const BadMonitoredItemFilterUnsupported& e) {
    std::string message{
        "The server does not support the requested monitored item filter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterNotAllowedTest) {
  try {
    throw_from_status(0x80450000);
    EXPECT_TRUE(false);
  } catch (const BadFilterNotAllowed& e) {
    std::string message{
        "A monitoring filter cannot be used in combination with the attribute "
        "specified."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadStructureMissingTest) {
  try {
    throw_from_status(0x80460000);
    EXPECT_TRUE(false);
  } catch (const BadStructureMissing& e) {
    std::string message{
        "A mandatory structured parameter was missing or null."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEventFilterInvalidTest) {
  try {
    throw_from_status(0x80470000);
    EXPECT_TRUE(false);
  } catch (const BadEventFilterInvalid& e) {
    std::string message{"The event filter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadContentFilterInvalidTest) {
  try {
    throw_from_status(0x80480000);
    EXPECT_TRUE(false);
  } catch (const BadContentFilterInvalid& e) {
    std::string message{"The content filter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterOperatorInvalidTest) {
  try {
    throw_from_status(0x80C10000);
    EXPECT_TRUE(false);
  } catch (const BadFilterOperatorInvalid& e) {
    std::string message{"An unregognized operator was provided in a filter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterOperatorUnsupportedTest) {
  try {
    throw_from_status(0x80C20000);
    EXPECT_TRUE(false);
  } catch (const BadFilterOperatorUnsupported& e) {
    std::string message{"A valid operator was provided"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterOperandCountMismatchTest) {
  try {
    throw_from_status(0x80C30000);
    EXPECT_TRUE(false);
  } catch (const BadFilterOperandCountMismatch& e) {
    std::string message{
        "The number of operands provided for the filter operator was less then "
        "expected for the operand provided."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterOperandInvalidTest) {
  try {
    throw_from_status(0x80490000);
    EXPECT_TRUE(false);
  } catch (const BadFilterOperandInvalid& e) {
    std::string message{"The operand used in a content filter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterElementInvalidTest) {
  try {
    throw_from_status(0x80C40000);
    EXPECT_TRUE(false);
  } catch (const BadFilterElementInvalid& e) {
    std::string message{
        "The referenced element is not a valid element in the content filter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadFilterLiteralInvalidTest) {
  try {
    throw_from_status(0x80C50000);
    EXPECT_TRUE(false);
  } catch (const BadFilterLiteralInvalid& e) {
    std::string message{"The referenced literal is not a valid value."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadContinuationPointInvalidTest) {
  try {
    throw_from_status(0x804A0000);
    EXPECT_TRUE(false);
  } catch (const BadContinuationPointInvalid& e) {
    std::string message{"The continuation point provide is longer valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoContinuationPointsTest) {
  try {
    throw_from_status(0x804B0000);
    EXPECT_TRUE(false);
  } catch (const BadNoContinuationPoints& e) {
    std::string message{
        "The operation could not be processed because all continuation points "
        "have been allocated."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadReferenceTypeIdInvalidTest) {
  try {
    throw_from_status(0x804C0000);
    EXPECT_TRUE(false);
  } catch (const BadReferenceTypeIdInvalid& e) {
    std::string message{
        "The operation could not be processed because all continuation points "
        "have been allocated."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadBrowseDirectionInvalidTest) {
  try {
    throw_from_status(0x804D0000);
    EXPECT_TRUE(false);
  } catch (const BadBrowseDirectionInvalid& e) {
    std::string message{"The browse direction is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeNotInViewTest) {
  try {
    throw_from_status(0x804E0000);
    EXPECT_TRUE(false);
  } catch (const BadNodeNotInView& e) {
    std::string message{"The node is not part of the view."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServerUriInvalidTest) {
  try {
    throw_from_status(0x804F0000);
    EXPECT_TRUE(false);
  } catch (const BadServerUriInvalid& e) {
    std::string message{"The ServerUri is not a valid URI."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServerNameMissingTest) {
  try {
    throw_from_status(0x80500000);
    EXPECT_TRUE(false);
  } catch (const BadServerNameMissing& e) {
    std::string message{"No ServerName was specified."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDiscoveryUrlMissingTest) {
  try {
    throw_from_status(0x80510000);
    EXPECT_TRUE(false);
  } catch (const BadDiscoveryUrlMissing& e) {
    std::string message{"No DiscoveryUrl was specified."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSempahoreFileMissingTest) {
  try {
    throw_from_status(0x80520000);
    EXPECT_TRUE(false);
  } catch (const BadSempahoreFileMissing& e) {
    std::string message{
        "The semaphore file specified by the client is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestTypeInvalidTest) {
  try {
    throw_from_status(0x80530000);
    EXPECT_TRUE(false);
  } catch (const BadRequestTypeInvalid& e) {
    std::string message{"The security token request type is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecurityModeRejectedTest) {
  try {
    throw_from_status(0x80540000);
    EXPECT_TRUE(false);
  } catch (const BadSecurityModeRejected& e) {
    std::string message{
        "The security mode does not meet the requirements set by the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecurityPolicyRejectedTest) {
  try {
    throw_from_status(0x80550000);
    EXPECT_TRUE(false);
  } catch (const BadSecurityPolicyRejected& e) {
    std::string message{
        "The security policy does not meet the requirements set by the "
        "server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManySessionsTest) {
  try {
    throw_from_status(0x80560000);
    EXPECT_TRUE(false);
  } catch (const BadTooManySessions& e) {
    std::string message{
        "The server has reached its maximum number of sessions."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadUserSignatureInvalidTest) {
  try {
    throw_from_status(0x80570000);
    EXPECT_TRUE(false);
  } catch (const BadUserSignatureInvalid& e) {
    std::string message{"The user token signature is missing or invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadApplicationSignatureInvalidTest) {
  try {
    throw_from_status(0x80580000);
    EXPECT_TRUE(false);
  } catch (const BadApplicationSignatureInvalid& e) {
    std::string message{
        "The signature generated with the client certificate is missing or "
        "invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoValidCertificatesTest) {
  try {
    throw_from_status(0x80590000);
    EXPECT_TRUE(false);
  } catch (const BadNoValidCertificates& e) {
    std::string message{
        "The client did not provide at least one software certificate that is "
        "valid and meets the profile requirements for the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadIdentityChangeNotSupportedTest) {
  try {
    throw_from_status(0x80C60000);
    EXPECT_TRUE(false);
  } catch (const BadIdentityChangeNotSupported& e) {
    std::string message{
        "The server does not support changing the user identity assigned to "
        "the session."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestCancelledByRequestTest) {
  try {
    throw_from_status(0x805A0000);
    EXPECT_TRUE(false);
  } catch (const BadRequestCancelledByRequest& e) {
    std::string message{
        "The request was cancelled by the client with the Cancel service."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadParentNodeIdInvalidTest) {
  try {
    throw_from_status(0x805B0000);
    EXPECT_TRUE(false);
  } catch (const BadParentNodeIdInvalid& e) {
    std::string message{
        "The parent node id does not to refer to a valid node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadReferenceNotAllowedTest) {
  try {
    throw_from_status(0x805C0000);
    EXPECT_TRUE(false);
  } catch (const BadReferenceNotAllowed& e) {
    std::string message{
        "The reference could not be created because it violates constraints "
        "imposed by the data model."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeIdRejectedTest) {
  try {
    throw_from_status(0x805D0000);
    EXPECT_TRUE(false);
  } catch (const BadNodeIdRejected& e) {
    std::string message{
        "The requested node id was reject because it was either invalid or "
        "server does not allow node ids to be specified by the client."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeIdExistsTest) {
  try {
    throw_from_status(0x805E0000);
    EXPECT_TRUE(false);
  } catch (const BadNodeIdExists& e) {
    std::string message{
        "The requested node id is already used by another node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeClassInvalidTest) {
  try {
    throw_from_status(0x805F0000);
    EXPECT_TRUE(false);
  } catch (const BadNodeClassInvalid& e) {
    std::string message{"The node class is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadBrowseNameInvalidTest) {
  try {
    throw_from_status(0x80600000);
    EXPECT_TRUE(false);
  } catch (const BadBrowseNameInvalid& e) {
    std::string message{"The browse name is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadBrowseNameDuplicatedTest) {
  try {
    throw_from_status(0x80610000);
    EXPECT_TRUE(false);
  } catch (const BadBrowseNameDuplicated& e) {
    std::string message{
        "The browse name is not unique among nodes that share the same "
        "relationship with the parent."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNodeAttributesInvalidTest) {
  try {
    throw_from_status(0x80620000);
    EXPECT_TRUE(false);
  } catch (const BadNodeAttributesInvalid& e) {
    std::string message{
        "The node attributes are not valid for the node class."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTypeDefinitionInvalidTest) {
  try {
    throw_from_status(0x80630000);
    EXPECT_TRUE(false);
  } catch (const BadTypeDefinitionInvalid& e) {
    std::string message{
        "The type definition node id does not reference an appropriate type "
        "node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSourceNodeIdInvalidTest) {
  try {
    throw_from_status(0x80640000);
    EXPECT_TRUE(false);
  } catch (const BadSourceNodeIdInvalid& e) {
    std::string message{"The source node id does not reference a valid node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTargetNodeIdInvalidTest) {
  try {
    throw_from_status(0x80650000);
    EXPECT_TRUE(false);
  } catch (const BadTargetNodeIdInvalid& e) {
    std::string message{"The target node id does not reference a valid node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDuplicateReferenceNotAllowedTest) {
  try {
    throw_from_status(0x80660000);
    EXPECT_TRUE(false);
  } catch (const BadDuplicateReferenceNotAllowed& e) {
    std::string message{
        "The reference type between the nodes is already defined."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInvalidSelfReferenceTest) {
  try {
    throw_from_status(0x80670000);
    EXPECT_TRUE(false);
  } catch (const BadInvalidSelfReference& e) {
    std::string message{
        "The server does not allow this type of self reference on this node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadReferenceLocalOnlyTest) {
  try {
    throw_from_status(0x80680000);
    EXPECT_TRUE(false);
  } catch (const BadReferenceLocalOnly& e) {
    std::string message{
        "The reference type is not valid for a reference to a remote server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoDeleteRightsTest) {
  try {
    throw_from_status(0x80690000);
    EXPECT_TRUE(false);
  } catch (const BadNoDeleteRights& e) {
    std::string message{"The server will not allow the node to be deleted."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainReferenceNotDeletedTest) {
  try {
    throw_from_status(0x40BC0000);
    EXPECT_TRUE(false);
  } catch (const UncertainReferenceNotDeleted& e) {
    std::string message{
        "The server was not able to delete all target references."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadServerIndexInvalidTest) {
  try {
    throw_from_status(0x806A0000);
    EXPECT_TRUE(false);
  } catch (const BadServerIndexInvalid& e) {
    std::string message{"The server index is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadViewIdUnknownTest) {
  try {
    throw_from_status(0x806B0000);
    EXPECT_TRUE(false);
  } catch (const BadViewIdUnknown& e) {
    std::string message{"The view id does not refer to a valid view node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadViewTimestampInvalidTest) {
  try {
    throw_from_status(0x80C90000);
    EXPECT_TRUE(false);
  } catch (const BadViewTimestampInvalid& e) {
    std::string message{
        "The view timestamp is not available or not supported."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadViewParameterMismatchTest) {
  try {
    throw_from_status(0x80CA0000);
    EXPECT_TRUE(false);
  } catch (const BadViewParameterMismatch& e) {
    std::string message{
        "The view parameters are not consistent with each other."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadViewVersionInvalidTest) {
  try {
    throw_from_status(0x80CB0000);
    EXPECT_TRUE(false);
  } catch (const BadViewVersionInvalid& e) {
    std::string message{"The view version is not available or not supported."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainNotAllNodesAvailableTest) {
  try {
    throw_from_status(0x40C00000);
    EXPECT_TRUE(false);
  } catch (const UncertainNotAllNodesAvailable& e) {
    std::string message{
        "The list of references may not be complete because the underlying "
        "system is not available."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodResultsMayBeIncompleteTest) {
  try {
    throw_from_status(0x00BA0000);
    EXPECT_TRUE(false);
  } catch (const GoodResultsMayBeIncomplete& e) {
    std::string message{
        "The server should have followed a reference to a node in a remote "
        "server but did not. The result set may be incomplete."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotTypeDefinitionTest) {
  try {
    throw_from_status(0x80C80000);
    EXPECT_TRUE(false);
  } catch (const BadNotTypeDefinition& e) {
    std::string message{
        "The provided Nodeid was not a type definition nodeid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainReferenceOutOfServerTest) {
  try {
    throw_from_status(0x406C0000);
    EXPECT_TRUE(false);
  } catch (const UncertainReferenceOutOfServer& e) {
    std::string message{
        "One of the references to follow in the relative path references to a "
        "node in the address space in another server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManyMatchesTest) {
  try {
    throw_from_status(0x806D0000);
    EXPECT_TRUE(false);
  } catch (const BadTooManyMatches& e) {
    std::string message{
        "The requested operation has too many matches to return."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadQueryTooComplexTest) {
  try {
    throw_from_status(0x806E0000);
    EXPECT_TRUE(false);
  } catch (const BadQueryTooComplex& e) {
    std::string message{
        "The requested operation requires too many resources in the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoMatchTest) {
  try {
    throw_from_status(0x806F0000);
    EXPECT_TRUE(false);
  } catch (const BadNoMatch& e) {
    std::string message{"The requested operation has no match to return."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMaxAgeInvalidTest) {
  try {
    throw_from_status(0x80700000);
    EXPECT_TRUE(false);
  } catch (const BadMaxAgeInvalid& e) {
    std::string message{"The max age parameter is invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecurityModeInsufficientTest) {
  try {
    throw_from_status(0x80E60000);
    EXPECT_TRUE(false);
  } catch (const BadSecurityModeInsufficient& e) {
    std::string message{
        "The operation is not permitted over the current secure channel."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadHistoryOperationInvalidTest) {
  try {
    throw_from_status(0x80710000);
    EXPECT_TRUE(false);
  } catch (const BadHistoryOperationInvalid& e) {
    std::string message{"The history details parameter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadHistoryOperationUnsupportedTest) {
  try {
    throw_from_status(0x80720000);
    EXPECT_TRUE(false);
  } catch (const BadHistoryOperationUnsupported& e) {
    std::string message{"The server does not support the requested operation."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInvalidTimestampArgumentTest) {
  try {
    throw_from_status(0x80BD0000);
    EXPECT_TRUE(false);
  } catch (const BadInvalidTimestampArgument& e) {
    std::string message{"The defined timestamp to return was invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadWriteNotSupportedTest) {
  try {
    throw_from_status(0x80730000);
    EXPECT_TRUE(false);
  } catch (const BadWriteNotSupported& e) {
    std::string message{
        "The server does not support writing the combination of value"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTypeMismatchTest) {
  try {
    throw_from_status(0x80740000);
    EXPECT_TRUE(false);
  } catch (const BadTypeMismatch& e) {
    std::string message{
        "The value supplied for the attribute is not of the same type as the "
        "attribute's value."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMethodInvalidTest) {
  try {
    throw_from_status(0x80750000);
    EXPECT_TRUE(false);
  } catch (const BadMethodInvalid& e) {
    std::string message{
        "The method id does not refer to a method for the specified object."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadArgumentsMissingTest) {
  try {
    throw_from_status(0x80760000);
    EXPECT_TRUE(false);
  } catch (const BadArgumentsMissing& e) {
    std::string message{
        "The client did not specify all of the input arguments for the "
        "method."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManySubscriptionsTest) {
  try {
    throw_from_status(0x80770000);
    EXPECT_TRUE(false);
  } catch (const BadTooManySubscriptions& e) {
    std::string message{
        "The server has reached its  maximum number of subscriptions."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTooManyPublishRequestsTest) {
  try {
    throw_from_status(0x80780000);
    EXPECT_TRUE(false);
  } catch (const BadTooManyPublishRequests& e) {
    std::string message{
        "The server has reached the maximum number of queued publish "
        "requests."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoSubscriptionTest) {
  try {
    throw_from_status(0x80790000);
    EXPECT_TRUE(false);
  } catch (const BadNoSubscription& e) {
    std::string message{"There is no subscription available for this session."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSequenceNumberUnknownTest) {
  try {
    throw_from_status(0x807A0000);
    EXPECT_TRUE(false);
  } catch (const BadSequenceNumberUnknown& e) {
    std::string message{"The sequence number is unknown to the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMessageNotAvailableTest) {
  try {
    throw_from_status(0x807B0000);
    EXPECT_TRUE(false);
  } catch (const BadMessageNotAvailable& e) {
    std::string message{
        "The requested notification message is no longer available."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInsufficientClientProfileTest) {
  try {
    throw_from_status(0x807C0000);
    EXPECT_TRUE(false);
  } catch (const BadInsufficientClientProfile& e) {
    std::string message{
        "The client of the current session does not support one or more "
        "Profiles that are necessary for the subscription."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadStateNotActiveTest) {
  try {
    throw_from_status(0x80BF0000);
    EXPECT_TRUE(false);
  } catch (const BadStateNotActive& e) {
    std::string message{"The sub-state machine is not currently active."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpServerTooBusyTest) {
  try {
    throw_from_status(0x807D0000);
    EXPECT_TRUE(false);
  } catch (const BadTcpServerTooBusy& e) {
    std::string message{
        "The server cannot process the request because it is too busy."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpMessageTypeInvalidTest) {
  try {
    throw_from_status(0x807E0000);
    EXPECT_TRUE(false);
  } catch (const BadTcpMessageTypeInvalid& e) {
    std::string message{
        "The type of the message specified in the header invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpSecureChannelUnknownTest) {
  try {
    throw_from_status(0x807F0000);
    EXPECT_TRUE(false);
  } catch (const BadTcpSecureChannelUnknown& e) {
    std::string message{
        "The SecureChannelId and/or TokenId are not currently in use."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpMessageTooLargeTest) {
  try {
    throw_from_status(0x80800000);
    EXPECT_TRUE(false);
  } catch (const BadTcpMessageTooLarge& e) {
    std::string message{
        "The size of the message specified in the header is too large."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpNotEnoughResourcesTest) {
  try {
    throw_from_status(0x80810000);
    EXPECT_TRUE(false);
  } catch (const BadTcpNotEnoughResources& e) {
    std::string message{
        "There are not enough resources to process the request."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpInternalErrorTest) {
  try {
    throw_from_status(0x80820000);
    EXPECT_TRUE(false);
  } catch (const BadTcpInternalError& e) {
    std::string message{"An internal error occurred."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTcpEndpointUrlInvalidTest) {
  try {
    throw_from_status(0x80830000);
    EXPECT_TRUE(false);
  } catch (const BadTcpEndpointUrlInvalid& e) {
    std::string message{
        "The server does not recognize the QueryString specified."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestInterruptedTest) {
  try {
    throw_from_status(0x80840000);
    EXPECT_TRUE(false);
  } catch (const BadRequestInterrupted& e) {
    std::string message{
        "The request could not be sent because of a network interruption."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestTimeoutTest) {
  try {
    throw_from_status(0x80850000);
    EXPECT_TRUE(false);
  } catch (const BadRequestTimeout& e) {
    std::string message{"Timeout occurred while processing the request."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecureChannelClosedTest) {
  try {
    throw_from_status(0x80860000);
    EXPECT_TRUE(false);
  } catch (const BadSecureChannelClosed& e) {
    std::string message{"The secure channel has been closed."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSecureChannelTokenUnknownTest) {
  try {
    throw_from_status(0x80870000);
    EXPECT_TRUE(false);
  } catch (const BadSecureChannelTokenUnknown& e) {
    std::string message{"The token has expired or is not recognized."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSequenceNumberInvalidTest) {
  try {
    throw_from_status(0x80880000);
    EXPECT_TRUE(false);
  } catch (const BadSequenceNumberInvalid& e) {
    std::string message{"The sequence number is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadProtocolVersionUnsupportedTest) {
  try {
    throw_from_status(0x80BE0000);
    EXPECT_TRUE(false);
  } catch (const BadProtocolVersionUnsupported& e) {
    std::string message{
        "The applications do not have compatible protocol versions."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConfigurationErrorTest) {
  try {
    throw_from_status(0x80890000);
    EXPECT_TRUE(false);
  } catch (const BadConfigurationError& e) {
    std::string message{
        "There is a problem with the configuration that affects the usefulness "
        "of the value."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNotConnectedTest) {
  try {
    throw_from_status(0x808A0000);
    EXPECT_TRUE(false);
  } catch (const BadNotConnected& e) {
    std::string message{
        "The variable should receive its value from another variable"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDeviceFailureTest) {
  try {
    throw_from_status(0x808B0000);
    EXPECT_TRUE(false);
  } catch (const BadDeviceFailure& e) {
    std::string message{
        "There has been a failure in the device/data source that generates the "
        "value that has affected the value."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSensorFailureTest) {
  try {
    throw_from_status(0x808C0000);
    EXPECT_TRUE(false);
  } catch (const BadSensorFailure& e) {
    std::string message{
        "There has been a failure in the sensor from which the value is "
        "derived by the device/data source."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadOutOfServiceTest) {
  try {
    throw_from_status(0x808D0000);
    EXPECT_TRUE(false);
  } catch (const BadOutOfService& e) {
    std::string message{"The source of the data is not operational."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDeadbandFilterInvalidTest) {
  try {
    throw_from_status(0x808E0000);
    EXPECT_TRUE(false);
  } catch (const BadDeadbandFilterInvalid& e) {
    std::string message{"The deadband filter is not valid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainNoCommunicationLastUsableValueTest) {
  try {
    throw_from_status(0x408F0000);
    EXPECT_TRUE(false);
  } catch (const UncertainNoCommunicationLastUsableValue& e) {
    std::string message{
        "Communication to the data source has failed. The variable value is "
        "the last value that had a good quality."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainLastUsableValueTest) {
  try {
    throw_from_status(0x40900000);
    EXPECT_TRUE(false);
  } catch (const UncertainLastUsableValue& e) {
    std::string message{
        "Whatever was updating this value has stopped doing so."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainSubstituteValueTest) {
  try {
    throw_from_status(0x40910000);
    EXPECT_TRUE(false);
  } catch (const UncertainSubstituteValue& e) {
    std::string message{
        "The value is an operational value that was manually overwritten."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainInitialValueTest) {
  try {
    throw_from_status(0x40920000);
    EXPECT_TRUE(false);
  } catch (const UncertainInitialValue& e) {
    std::string message{
        "The value is an initial value for a variable that normally receives "
        "its value from another variable."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainSensorNotAccurateTest) {
  try {
    throw_from_status(0x40930000);
    EXPECT_TRUE(false);
  } catch (const UncertainSensorNotAccurate& e) {
    std::string message{"The value is at one of the sensor limits."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainEngineeringUnitsExceededTest) {
  try {
    throw_from_status(0x40940000);
    EXPECT_TRUE(false);
  } catch (const UncertainEngineeringUnitsExceeded& e) {
    std::string message{
        "The value is outside of the range of values defined for this "
        "parameter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainSubNormalTest) {
  try {
    throw_from_status(0x40950000);
    EXPECT_TRUE(false);
  } catch (const UncertainSubNormal& e) {
    std::string message{
        "The value is derived from multiple sources and has less than the "
        "required number of Good sources."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodLocalOverrideTest) {
  try {
    throw_from_status(0x00960000);
    EXPECT_TRUE(false);
  } catch (const GoodLocalOverride& e) {
    std::string message{"The value has been overridden."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRefreshInProgressTest) {
  try {
    throw_from_status(0x80970000);
    EXPECT_TRUE(false);
  } catch (const BadRefreshInProgress& e) {
    std::string message{"This Condition refresh failed"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionAlreadyDisabledTest) {
  try {
    throw_from_status(0x80980000);
    EXPECT_TRUE(false);
  } catch (const BadConditionAlreadyDisabled& e) {
    std::string message{"This condition has already been disabled."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionAlreadyEnabledTest) {
  try {
    throw_from_status(0x80CC0000);
    EXPECT_TRUE(false);
  } catch (const BadConditionAlreadyEnabled& e) {
    std::string message{"This condition has already been enabled."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionDisabledTest) {
  try {
    throw_from_status(0x80990000);
    EXPECT_TRUE(false);
  } catch (const BadConditionDisabled& e) {
    std::string message{"Property not available"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEventIdUnknownTest) {
  try {
    throw_from_status(0x809A0000);
    EXPECT_TRUE(false);
  } catch (const BadEventIdUnknown& e) {
    std::string message{"The specified event id is not recognized."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEventNotAcknowledgeableTest) {
  try {
    throw_from_status(0x80BB0000);
    EXPECT_TRUE(false);
  } catch (const BadEventNotAcknowledgeable& e) {
    std::string message{"The event cannot be acknowledged."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDialogNotActiveTest) {
  try {
    throw_from_status(0x80CD0000);
    EXPECT_TRUE(false);
  } catch (const BadDialogNotActive& e) {
    std::string message{"The dialog condition is not active."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDialogResponseInvalidTest) {
  try {
    throw_from_status(0x80CE0000);
    EXPECT_TRUE(false);
  } catch (const BadDialogResponseInvalid& e) {
    std::string message{"The response is not valid for the dialog."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionBranchAlreadyAckedTest) {
  try {
    throw_from_status(0x80CF0000);
    EXPECT_TRUE(false);
  } catch (const BadConditionBranchAlreadyAcked& e) {
    std::string message{"The condition branch has already been acknowledged."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionBranchAlreadyConfirmedTest) {
  try {
    throw_from_status(0x80D00000);
    EXPECT_TRUE(false);
  } catch (const BadConditionBranchAlreadyConfirmed& e) {
    std::string message{"The condition branch has already been confirmed."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionAlreadyShelvedTest) {
  try {
    throw_from_status(0x80D10000);
    EXPECT_TRUE(false);
  } catch (const BadConditionAlreadyShelved& e) {
    std::string message{"The condition has already been shelved."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConditionNotShelvedTest) {
  try {
    throw_from_status(0x80D20000);
    EXPECT_TRUE(false);
  } catch (const BadConditionNotShelved& e) {
    std::string message{"The condition is not currently shelved."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadShelvingTimeOutOfRangeTest) {
  try {
    throw_from_status(0x80D30000);
    EXPECT_TRUE(false);
  } catch (const BadShelvingTimeOutOfRange& e) {
    std::string message{"The shelving time not within an acceptable range."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoDataTest) {
  try {
    throw_from_status(0x809B0000);
    EXPECT_TRUE(false);
  } catch (const BadNoData& e) {
    std::string message{
        "No data exists for the requested time range or event filter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadBoundNotFoundTest) {
  try {
    throw_from_status(0x80D70000);
    EXPECT_TRUE(false);
  } catch (const BadBoundNotFound& e) {
    std::string message{"No data found to provide upper or lower bound value."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadBoundNotSupportedTest) {
  try {
    throw_from_status(0x80D80000);
    EXPECT_TRUE(false);
  } catch (const BadBoundNotSupported& e) {
    std::string message{"The server cannot retrieve a bound for the variable."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDataLostTest) {
  try {
    throw_from_status(0x809D0000);
    EXPECT_TRUE(false);
  } catch (const BadDataLost& e) {
    std::string message{
        "Data is missing due to collection started/stopped/lost."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDataUnavailableTest) {
  try {
    throw_from_status(0x809E0000);
    EXPECT_TRUE(false);
  } catch (const BadDataUnavailable& e) {
    std::string message{
        "Expected data is unavailable for the requested time range due to an "
        "un-mounted volume"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEntryExistsTest) {
  try {
    throw_from_status(0x809F0000);
    EXPECT_TRUE(false);
  } catch (const BadEntryExists& e) {
    std::string message{
        "The data or event was not successfully inserted because a matching "
        "entry exists."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoEntryExistsTest) {
  try {
    throw_from_status(0x80A00000);
    EXPECT_TRUE(false);
  } catch (const BadNoEntryExists& e) {
    std::string message{
        "The data or event was not successfully updated because no matching "
        "entry exists."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadTimestampNotSupportedTest) {
  try {
    throw_from_status(0x80A10000);
    EXPECT_TRUE(false);
  } catch (const BadTimestampNotSupported& e) {
    std::string message{
        "The client requested history using a timestamp format the server does "
        "not support (i.e requested ServerTimestamp when server only supports "
        "SourceTimestamp)."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodEntryInsertedTest) {
  try {
    throw_from_status(0x00A20000);
    EXPECT_TRUE(false);
  } catch (const GoodEntryInserted& e) {
    std::string message{
        "The data or event was successfully inserted into the historical "
        "database."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodEntryReplacedTest) {
  try {
    throw_from_status(0x00A30000);
    EXPECT_TRUE(false);
  } catch (const GoodEntryReplaced& e) {
    std::string message{
        "The data or event field was successfully replaced in the historical "
        "database."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainDataSubNormalTest) {
  try {
    throw_from_status(0x40A40000);
    EXPECT_TRUE(false);
  } catch (const UncertainDataSubNormal& e) {
    std::string message{
        "The value is derived from multiple values and has less than the "
        "required number of Good values."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodNoDataTest) {
  try {
    throw_from_status(0x00A50000);
    EXPECT_TRUE(false);
  } catch (const GoodNoData& e) {
    std::string message{
        "No data exists for the requested time range or event filter."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodMoreDataTest) {
  try {
    throw_from_status(0x00A60000);
    EXPECT_TRUE(false);
  } catch (const GoodMoreData& e) {
    std::string message{
        "The data or event field was successfully replaced in the historical "
        "database."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadAggregateListMismatchTest) {
  try {
    throw_from_status(0x80D40000);
    EXPECT_TRUE(false);
  } catch (const BadAggregateListMismatch& e) {
    std::string message{
        "The requested number of Aggregates does not match the requested "
        "number of NodeIds."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadAggregateNotSupportedTest) {
  try {
    throw_from_status(0x80D50000);
    EXPECT_TRUE(false);
  } catch (const BadAggregateNotSupported& e) {
    std::string message{
        "The requested Aggregate is not support by the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadAggregateInvalidInputsTest) {
  try {
    throw_from_status(0x80D60000);
    EXPECT_TRUE(false);
  } catch (const BadAggregateInvalidInputs& e) {
    std::string message{
        "The aggregate value could not be derived due to invalid data inputs."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadAggregateConfigurationRejectedTest) {
  try {
    throw_from_status(0x80DA0000);
    EXPECT_TRUE(false);
  } catch (const BadAggregateConfigurationRejected& e) {
    std::string message{
        "The aggregate configuration is not valid for specified node."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodDataIgnoredTest) {
  try {
    throw_from_status(0x00D90000);
    EXPECT_TRUE(false);
  } catch (const GoodDataIgnored& e) {
    std::string message{
        "The request pecifies fields which are not valid for the EventType or "
        "cannot be saved by the historian."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadRequestNotAllowedTest) {
  try {
    throw_from_status(0x80E40000);
    EXPECT_TRUE(false);
  } catch (const BadRequestNotAllowed& e) {
    std::string message{
        "The request was rejected by the server because it did not meet the "
        "criteria set by the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodEditedTest) {
  try {
    throw_from_status(0x00DC0000);
    EXPECT_TRUE(false);
  } catch (const GoodEdited& e) {
    std::string message{
        "The value does not come from the real source and has been edited by "
        "the server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodPostActionFailedTest) {
  try {
    throw_from_status(0x00DD0000);
    EXPECT_TRUE(false);
  } catch (const GoodPostActionFailed& e) {
    std::string message{
        "There was an error in execution of these post-actions."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainDominantValueChangedTest) {
  try {
    throw_from_status(0x40DE0000);
    EXPECT_TRUE(false);
  } catch (const UncertainDominantValueChanged& e) {
    std::string message{
        "The related EngineeringUnit has been changed but the Variable Value "
        "is still provided based on the previous unit."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodDependentValueChangedTest) {
  try {
    throw_from_status(0x00E00000);
    EXPECT_TRUE(false);
  } catch (const GoodDependentValueChanged& e) {
    std::string message{
        "A dependent value has been changed but the change has not been "
        "applied to the device."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDominantValueChangedTest) {
  try {
    throw_from_status(0x80E10000);
    EXPECT_TRUE(false);
  } catch (const BadDominantValueChanged& e) {
    std::string message{
        "The related EngineeringUnit has been changed but this change has not "
        "been applied to the device. The Variable Value is still dependent on "
        "the previous unit but its status is currently Bad."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, UncertainDependentValueChangedTest) {
  try {
    throw_from_status(0x40E20000);
    EXPECT_TRUE(false);
  } catch (const UncertainDependentValueChanged& e) {
    std::string message{
        "A dependent value has been changed but the change has not been "
        "applied to the device. The quality of the dominant variable is "
        "uncertain."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDependentValueChangedTest) {
  try {
    throw_from_status(0x80E30000);
    EXPECT_TRUE(false);
  } catch (const BadDependentValueChanged& e) {
    std::string message{
        "A dependent value has been changed but the change has not been "
        "applied to the device. The quality of the dominant variable is Bad."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodCommunicationEventTest) {
  try {
    throw_from_status(0x00A70000);
    EXPECT_TRUE(false);
  } catch (const GoodCommunicationEvent& e) {
    std::string message{"The communication layer has raised an event."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodShutdownEventTest) {
  try {
    throw_from_status(0x00A80000);
    EXPECT_TRUE(false);
  } catch (const GoodShutdownEvent& e) {
    std::string message{"The system is shutting down."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodCallAgainTest) {
  try {
    throw_from_status(0x00A90000);
    EXPECT_TRUE(false);
  } catch (const GoodCallAgain& e) {
    std::string message{
        "The operation is not finished and needs to be called again."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, GoodNonCriticalTimeoutTest) {
  try {
    throw_from_status(0x00AA0000);
    EXPECT_TRUE(false);
  } catch (const GoodNonCriticalTimeout& e) {
    std::string message{"A non-critical timeout occurred."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInvalidArgumentTest) {
  try {
    throw_from_status(0x80AB0000);
    EXPECT_TRUE(false);
  } catch (const BadInvalidArgument& e) {
    std::string message{"One or more arguments are invalid."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConnectionRejectedTest) {
  try {
    throw_from_status(0x80AC0000);
    EXPECT_TRUE(false);
  } catch (const BadConnectionRejected& e) {
    std::string message{
        "Could not establish a network connection to remote server."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadDisconnectTest) {
  try {
    throw_from_status(0x80AD0000);
    EXPECT_TRUE(false);
  } catch (const BadDisconnect& e) {
    std::string message{"The server has disconnected from the client."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadConnectionClosedTest) {
  try {
    throw_from_status(0x80AE0000);
    EXPECT_TRUE(false);
  } catch (const BadConnectionClosed& e) {
    std::string message{"The network connection has been closed."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadInvalidStateTest) {
  try {
    throw_from_status(0x80AF0000);
    EXPECT_TRUE(false);
  } catch (const BadInvalidState& e) {
    std::string message{
        "The operation cannot be completed because the object is closed"};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadEndOfStreamTest) {
  try {
    throw_from_status(0x80B00000);
    EXPECT_TRUE(false);
  } catch (const BadEndOfStream& e) {
    std::string message{"Cannot move beyond end of the stream."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadNoDataAvailableTest) {
  try {
    throw_from_status(0x80B10000);
    EXPECT_TRUE(false);
  } catch (const BadNoDataAvailable& e) {
    std::string message{
        "No data is currently available for reading from a non-blocking "
        "stream."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadWaitingForResponseTest) {
  try {
    throw_from_status(0x80B20000);
    EXPECT_TRUE(false);
  } catch (const BadWaitingForResponse& e) {
    std::string message{
        "The asynchronous operation is waiting for a response."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadOperationAbandonedTest) {
  try {
    throw_from_status(0x80B30000);
    EXPECT_TRUE(false);
  } catch (const BadOperationAbandoned& e) {
    std::string message{
        "The asynchronous operation was abandoned by the caller."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadExpectedStreamToBlockTest) {
  try {
    throw_from_status(0x80B40000);
    EXPECT_TRUE(false);
  } catch (const BadExpectedStreamToBlock& e) {
    std::string message{
        "The stream did not return all data requested (possibly because it is "
        "a non-blocking stream)."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadWouldBlockTest) {
  try {
    throw_from_status(0x80B50000);
    EXPECT_TRUE(false);
  } catch (const BadWouldBlock& e) {
    std::string message{
        "Non blocking behaviour is required and the operation would block."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadSyntaxErrorTest) {
  try {
    throw_from_status(0x80B60000);
    EXPECT_TRUE(false);
  } catch (const BadSyntaxError& e) {
    std::string message{"A value had an invalid syntax."};
    EXPECT_EQ(message, e.what());
  }
}

TEST_F(OpcuaExceptionTest, BadMaxConnectionsReachedTest) {
  try {
    throw_from_status(0x80B70000);
    EXPECT_TRUE(false);
  } catch (const BadMaxConnectionsReached& e) {
    std::string message{
        "The operation could not be finished because all available connections "
        "are in use."};
    EXPECT_EQ(message, e.what());
  }
}

}  // namespace opcua::diag::test