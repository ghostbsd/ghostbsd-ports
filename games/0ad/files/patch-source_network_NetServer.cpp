--- source/network/NetServer.cpp.orig	2022-09-23 19:17:14 UTC
+++ source/network/NetServer.cpp
@@ -302,7 +302,11 @@ void CNetServerWorker::SetupUPnP()
 	else if ((devlist = upnpDiscover(10000, 0, 0, 0, 0, 0)) != NULL)
 #endif
 	{
+#if defined(MINIUPNPC_API_VERSION) && MINIUPNPC_API_VERSION >= 18
+		ret = UPNP_GetValidIGD(devlist, &urls, &data, internalIPAddress, sizeof(internalIPAddress), NULL, 0);
+#else
 		ret = UPNP_GetValidIGD(devlist, &urls, &data, internalIPAddress, sizeof(internalIPAddress));
+#endif
 		allocatedUrls = ret != 0; // urls is allocated on non-zero return values
 	}
 	else
@@ -321,9 +325,18 @@ void CNetServerWorker::SetupUPnP()
 		LOGMESSAGE("Net server: found valid IGD = %s", urls.controlURL);
 		break;
 	case 2:
+#if defined(MINIUPNPC_API_VERSION) && MINIUPNPC_API_VERSION >= 18
+		LOGMESSAGE("Net server: found a valid IGD with a reserved address = %s, will try to continue anyway", urls.controlURL);
+		break;
+	case 3:
 		LOGMESSAGE("Net server: found a valid, not connected IGD = %s, will try to continue anyway", urls.controlURL);
 		break;
+	case 4:
+#else
+		LOGMESSAGE("Net server: found a valid, not connected IGD = %s, will try to continue anyway", urls.controlURL);
+		break;
 	case 3:
+#endif
 		LOGMESSAGE("Net server: found a UPnP device unrecognized as IGD = %s, will try to continue anyway", urls.controlURL);
 		break;
 	default:
